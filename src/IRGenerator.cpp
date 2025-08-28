//
// Created by Fan Long on 2020/12/6.
//

//add more header files if your want
#include "IRGenerator.h"
#include "llvm/IR/Module.h"
#include "Declarations.h"
#include "Program.h"
#include "Exprs.h"
#include "Statements.h"
#include "ASTNode.h"
#include "llvm/IR/Verifier.h"



static std::map<minicc::Expr*, llvm::Value*> my_map;





namespace minicc {
    //add your member helper functions

    void IRGenerator::setExprValue(Expr* expr, llvm::Value* value) {
        my_map[expr] = value;
    }

    llvm::Value* IRGenerator::getExprValue(Expr* expr) {
        auto it = my_map.find(expr);
        if (it != my_map.end()) {
            return it->second;
        }
        return nullptr;
    }

    llvm::Type* IRGenerator::getLLVMType(Type::PrimitiveTypeEnum type, size_t k) {
        llvm::Type* baseType = nullptr;
        if (type == Type::Int) {
            baseType = llvm::Type::getInt32Ty(*TheContext);
        } 
        else if (type == Type::Bool) {
            baseType = llvm::Type::getInt1Ty(*TheContext);
        } 
        else if (type == Type::Char) {
            baseType = llvm::Type::getInt8Ty(*TheContext);
        } 
        else if (type == Type::Void) {
            baseType = llvm::Type::getVoidTy(*TheContext);
        } 
        else {
            return nullptr;
        }

        if (k > 0) {
            return llvm::ArrayType::get(baseType, k);
        }

        return baseType;
    }

    void IRGenerator::insertSyslibDeclarations() {
        {
            llvm::FunctionType* ftype = llvm::FunctionType::get(llvm::Type::getInt32Ty(*TheContext),false);
            TheModule->getOrInsertFunction("getint", ftype);
        }
        {
            std::vector<llvm::Type*> argTypes{ llvm::Type::getInt32Ty(*TheContext) };
            llvm::FunctionType* ftype = llvm::FunctionType::get(llvm::Type::getVoidTy(*TheContext), argTypes, false);
            TheModule->getOrInsertFunction("putint", ftype);
        }
        {
            llvm::FunctionType* ftyp = llvm::FunctionType::get(llvm::Type::getVoidTy(*TheContext), false );
            TheModule->getOrInsertFunction("putnewline", ftyp);
        }
    }







    void IRGenerator::visitProgram(Program *prog) {
        TheModule  = std::make_unique<llvm::Module>(ModuleName, *TheContext);
        TheBuilder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
        insertSyslibDeclarations();
        for (size_t i = 0; i < prog->numChildren(); i++) {
            prog->getChild(i)->accept(this);
        }
    }

    void IRGenerator::visitVarDecl(VarDeclaration *decl) {

        Type::PrimitiveTypeEnum mytype = decl->declType();
        ASTNode* parent = decl->getParent();
        bool isGlobal = parent->isProgram();

        for (size_t i = 0; i < decl->numVarReferences(); i++) {
            VarReference* myvar = decl->varReference(i);
            std::string vars = myvar->identifier()->name();
            size_t k = 0;
            if (myvar->isArray()) {
                auto* array_size = dynamic_cast<IntLiteralExpr*>(myvar->indexExpr());
                if (array_size) {
                    k = array_size->value();
                }
            }
            llvm::Type* varType = getLLVMType(mytype, k);
            if (isGlobal) {
                llvm::Constant* init = nullptr;
                if (k > 0) {
                    init = llvm::ConstantAggregateZero::get(varType);
                } else {
                    switch (mytype) {
                        case Type::Int:
                        case Type::Bool:
                        case Type::Char:
                            init = llvm::ConstantInt::get(varType, 0);
                            break;
                        default:
                            init = nullptr; 
                    }
                }

                auto *global_var_ptr = new llvm::GlobalVariable(*TheModule, 
                                                            varType, 
                                                            false,
                                                            llvm::GlobalValue::CommonLinkage,
                                                            init,
                                                            vars);

                parent->scopeVarTable()->setLLVMValue(vars, global_var_ptr);

            } else {
                llvm::Function* my_func = TheBuilder->GetInsertBlock()->getParent();
                llvm::IRBuilder<> entry_builder(&my_func->getEntryBlock(), my_func->getEntryBlock().begin());
                llvm::AllocaInst* alloca = entry_builder.CreateAlloca(varType, nullptr, vars);
                parent->scopeVarTable()->setLLVMValue(vars, alloca);
            }

        }
    }

    void IRGenerator::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
        std::string name = func->name();

        llvm::Type* returnType = (name == "main")? llvm::Type::getInt32Ty(*TheContext) : getLLVMType(func->returnType().primitiveType());

        std::vector<llvm::Type*> parram_types;

        for (size_t i = 0; i < func->numParameters(); i++) {
            Parameter* p = func->parameter(i);
            parram_types.push_back(getLLVMType(p->type().primitiveType()));
        }

        llvm::FunctionType* function_type = llvm::FunctionType::get(returnType, parram_types, false);
        llvm::Function* my_func = TheModule->getFunction(name);
        if (my_func) {
            if (my_func->getFunctionType() != function_type) {
                return;
            }
        } else {
            my_func = llvm::Function::Create(function_type, llvm::Function::ExternalLinkage, name, TheModule.get());
        }

        unsigned q = 0;
        for (auto &arg : my_func->args()) {
            arg.setName(func->parameter(q)->name());
            q++;
        }

        if (func->hasBody()) {
            llvm::BasicBlock* lhs_block = llvm::BasicBlock::Create(*TheContext, "entry", my_func);
            TheBuilder->SetInsertPoint(lhs_block);

            q = 0;
            for (auto &arg : my_func->args()) {
                llvm::AllocaInst* alloca = TheBuilder->CreateAlloca(arg.getType(), nullptr, arg.getName());
                TheBuilder->CreateStore(&arg, alloca);
                func->body()->scopeVarTable()->setLLVMValue(std::string(arg.getName()), alloca);
                q++;
            }

            func->body()->accept(this);

            if (!TheBuilder->GetInsertBlock()->getTerminator()) {
                if (returnType->isVoidTy()) {
                    TheBuilder->CreateRetVoid();
                } else if (name == "main") {
                    TheBuilder->CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0));
                }
            }
        }
    }

    void IRGenerator::visitIfStmt(IfStatement *stmt) {

        stmt->condExpr()->accept(this);
        llvm::Value* if_cond_val = getExprValue(stmt->condExpr());
        if (!if_cond_val) return;
        llvm::Function* my_func = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock* if_then_block = llvm::BasicBlock::Create(*TheContext, "then", my_func);
        llvm::BasicBlock* if_else_block = nullptr;
        llvm::BasicBlock* logical_merge_block = llvm::BasicBlock::Create(*TheContext, "ifcont", my_func);

        if (stmt->hasElse()) {
            if_else_block = llvm::BasicBlock::Create(*TheContext, "else", my_func);
            TheBuilder->CreateCondBr(if_cond_val, if_then_block, if_else_block);
        } else {
            TheBuilder->CreateCondBr(if_cond_val, if_then_block, logical_merge_block);
        }



        TheBuilder->SetInsertPoint(if_then_block);
        stmt->thenStmt()->accept(this);
        if (!TheBuilder->GetInsertBlock()->getTerminator()) {
            TheBuilder->CreateBr(logical_merge_block);
        }


        if (stmt->hasElse()) {
            TheBuilder->SetInsertPoint(if_else_block);
            stmt->elseStmt()->accept(this);
            if (!TheBuilder->GetInsertBlock()->getTerminator()) {
                TheBuilder->CreateBr(logical_merge_block);
            }
        }

        TheBuilder->SetInsertPoint(logical_merge_block);
    }


    void IRGenerator::visitForStmt(ForStatement *stmt) {
        //start your code her
        llvm::Function* my_func = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock* for_cond_block = llvm::BasicBlock::Create(*TheContext, "for.cond", my_func);
        llvm::BasicBlock* for_body_block = llvm::BasicBlock::Create(*TheContext, "for.body", my_func);
        llvm::BasicBlock* for_update_block =llvm::BasicBlock::Create(*TheContext, "for.update", my_func);
        llvm::BasicBlock* for_exit_block = llvm::BasicBlock::Create(*TheContext, "for.exit", my_func);

        breakDestMap[stmt] = for_exit_block;
        continueDestMap[stmt] = for_update_block;

        if (stmt->initExpr()) { 
            stmt->initExpr()->accept(this);
        }

        TheBuilder->CreateBr(for_cond_block);
        TheBuilder->SetInsertPoint(for_cond_block);

        llvm::Value* if_cond_val = nullptr;

        if (stmt->condExpr()) {
            stmt->condExpr()->accept(this);
            if_cond_val = getExprValue(stmt->condExpr());
        } else {
            if_cond_val = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 1);
        }

        TheBuilder->CreateCondBr(if_cond_val, for_body_block, for_exit_block);
        TheBuilder->SetInsertPoint(for_body_block);

        stmt->body()->accept(this);
        if (!TheBuilder->GetInsertBlock()->getTerminator()) {
            TheBuilder->CreateBr(for_update_block);
        }

        TheBuilder->SetInsertPoint(for_update_block);

        if (stmt->iterExpr()) {stmt->iterExpr()->accept(this); }

        TheBuilder->CreateBr(for_cond_block);
        TheBuilder->SetInsertPoint(for_exit_block);

        breakDestMap.erase(stmt);
        continueDestMap.erase(stmt);
    }

    void IRGenerator::visitWhileStmt(WhileStatement *stmt) {
        llvm::Function* my_func = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock* while_cond_block = llvm::BasicBlock::Create(*TheContext, "while.cond", my_func);
        llvm::BasicBlock* while_body_block = llvm::BasicBlock::Create(*TheContext, "while.body", my_func);
        llvm::BasicBlock* for_exit_block = llvm::BasicBlock::Create(*TheContext, "while.exit", my_func);


        breakDestMap[stmt] = for_exit_block;
        continueDestMap[stmt] = while_cond_block;

        TheBuilder->CreateBr(while_cond_block);
        TheBuilder->SetInsertPoint(while_cond_block);

        stmt->condExpr()->accept(this);

        llvm::Value* if_cond_val = getExprValue(stmt->condExpr());

        TheBuilder->CreateCondBr(if_cond_val, while_body_block, for_exit_block);
        TheBuilder->SetInsertPoint(while_body_block);

        stmt->body()->accept(this);
        if (!TheBuilder->GetInsertBlock()->getTerminator()) {
            TheBuilder->CreateBr(while_cond_block);
        }

        TheBuilder->SetInsertPoint(for_exit_block);

        breakDestMap.erase(stmt);
        continueDestMap.erase(stmt);
    }

    void IRGenerator::visitReturnStmt(ReturnStatement *stmt) {

        if (stmt->hasReturnExpr()) {
            stmt->returnExpr()->accept(this);
            llvm::Value* retVal = getExprValue(stmt->returnExpr());
            TheBuilder->CreateRet(retVal);
        } else {
            TheBuilder->CreateRetVoid();
        }
    }

    void IRGenerator::visitBreakStmt(BreakStatement *stmt) {
        WhileStatement* whileStmt = stmt->getParentWhileStatement();
        ForStatement* forStmt = stmt->getParentForStatement();

        if (whileStmt && breakDestMap.count(whileStmt)) {
            TheBuilder->CreateBr(breakDestMap[whileStmt]);
        } else if (forStmt && breakDestMap.count(forStmt)) {
            TheBuilder->CreateBr(breakDestMap[forStmt]);
        }
    }
    void IRGenerator::visitScope(ScopeStatement *stmt) {
        for (size_t i = 0; i < stmt->numChildren(); i++) {
            stmt->getChild(i)->accept(this);
            if (TheBuilder->GetInsertBlock()->getTerminator()) {
                break;
            }
        }
    }

    void IRGenerator::visitUnaryExpr(UnaryExpr *expr) {
        expr->getChild(0)->accept(this);
        llvm::Value* operand = getExprValue((Expr*)expr->getChild(0));
        if (!operand) return;

        llvm::Value* result = nullptr;
        switch (expr->opcode()) {
            case Expr::Sub:
                result = TheBuilder->CreateNeg(operand, "negtmp");
                break;
            case Expr::Not:
                result = TheBuilder->CreateNot(operand, "nottmp");
                break;
            default:
                return;
        }
        setExprValue(expr, result);
    }

 
    void IRGenerator::visitBinaryExpr(BinaryExpr *expr) {

        if (expr->opcode() == Expr::And) {
            llvm::Function* f = TheBuilder->GetInsertBlock()->getParent();
            expr->getChild(0)->accept(this);
            llvm::Value* lhs = getExprValue((Expr*)expr->getChild(0));
            if (!lhs) return;

            llvm::BasicBlock* rhsBlock = llvm::BasicBlock::Create(*TheContext, "and.rhs", f);
            llvm::BasicBlock* logicalMergeBlock = llvm::BasicBlock::Create(*TheContext, "and.end", f);
            llvm::BasicBlock* lhsBlock = TheBuilder->GetInsertBlock();

            TheBuilder->CreateCondBr(lhs, rhsBlock, logicalMergeBlock);

            TheBuilder->SetInsertPoint(rhsBlock);
            expr->getChild(1)->accept(this);
            llvm::Value* rhs = getExprValue((Expr*)expr->getChild(1));
            if (!rhs) return;
            llvm::BasicBlock* rb = TheBuilder->GetInsertBlock();
            TheBuilder->CreateBr(logicalMergeBlock);

            TheBuilder->SetInsertPoint(logicalMergeBlock);
            llvm::PHINode* phi = TheBuilder->CreatePHI(llvm::Type::getInt1Ty(*TheContext), 2, "andtmp");
            phi->addIncoming(llvm::ConstantInt::getFalse(*TheContext), lhsBlock);
            phi->addIncoming(rhs, rb);

            setExprValue(expr, phi);
            return;

        } else if (expr->opcode() == Expr::Or) {
            llvm::Function* f = TheBuilder->GetInsertBlock()->getParent();
            expr->getChild(0)->accept(this);
            llvm::Value* lhs = getExprValue((Expr*)expr->getChild(0));
            if (!lhs) return;

            llvm::BasicBlock* rhsBlock = llvm::BasicBlock::Create(*TheContext, "or.rhs", f);
            llvm::BasicBlock* logicalMergeBlock = llvm::BasicBlock::Create(*TheContext, "or.end", f);
            llvm::BasicBlock* lhsBlock = TheBuilder->GetInsertBlock();

            TheBuilder->CreateCondBr(lhs,logicalMergeBlock, rhsBlock);

            TheBuilder->SetInsertPoint(rhsBlock);
            expr->getChild(1)->accept(this);
            llvm::Value* rhs = getExprValue((Expr*)expr->getChild(1));
            if (!rhs) return;
            llvm::BasicBlock* rb = TheBuilder->GetInsertBlock();
            TheBuilder->CreateBr(logicalMergeBlock);

            TheBuilder->SetInsertPoint(logicalMergeBlock);
            llvm::PHINode* phi = TheBuilder->CreatePHI(llvm::Type::getInt1Ty(*TheContext), 2, "ortmp");
            phi->addIncoming(llvm::ConstantInt::getTrue(*TheContext), lhsBlock);
            phi->addIncoming(rhs, rb);

            setExprValue(expr, phi);
            return;
        }

        expr->getChild(0)->accept(this);
        expr->getChild(1)->accept(this);
        llvm::Value* lhs = getExprValue((Expr*)expr->getChild(0));
        llvm::Value* rhs = getExprValue((Expr*)expr->getChild(1));
        if (!lhs || !rhs) return;

        llvm::Value* result = nullptr;
        switch (expr->opcode()) {
            case Expr::Add:
                result = TheBuilder->CreateAdd(lhs, rhs, "addtmp");
                break;
            case Expr::Sub:
                result = TheBuilder->CreateSub(lhs, rhs, "subtmp");
                break;
            case Expr::Mul:
                result = TheBuilder->CreateMul(lhs, rhs, "multmp");
                break;
            case Expr::Div:
                result = TheBuilder->CreateSDiv(lhs, rhs, "divtmp");
                break;
            case Expr::Equal:
                result = TheBuilder->CreateICmpEQ(lhs, rhs, "eqtmp");
                break;
            case Expr::NotEqual:
                result = TheBuilder->CreateICmpNE(lhs, rhs, "netmp");
                break;
            case Expr::Less:
                result = TheBuilder->CreateICmpSLT(lhs, rhs, "lttmp");
                break;
            case Expr::LessEqual:
                result = TheBuilder->CreateICmpSLE(lhs, rhs, "letmp");
                break;
            case Expr::Greater:
                result = TheBuilder->CreateICmpSGT(lhs, rhs, "gttmp");
                break;
            case Expr::GreaterEqual:
                result = TheBuilder->CreateICmpSGE(lhs, rhs, "getmp");
                break;
            default:
                return;
        }

        setExprValue(expr, result);
    }

    void IRGenerator::visitCallExpr(CallExpr *expr) {

        std::string name = expr->callee()->name();
        llvm::Function* called_function = TheModule->getFunction(name);
        if (!called_function) {
            return;
        }
        std::vector<llvm::Value*> argVals;
        for (size_t i = 0; i < expr->numArgs(); i++) {
            expr->arg(i)->accept(this);
            llvm::Value* val = getExprValue(expr->arg(i));
            if (!val) return;
            argVals.push_back(val);
        }
        if (called_function->getReturnType()->isVoidTy()) {
            TheBuilder->CreateCall(called_function, argVals);
        } else {
            llvm::Value* res = TheBuilder->CreateCall(called_function, argVals, "calltmp");
            setExprValue(expr, res);
        }
    }

    void IRGenerator::visitVarExpr(VarExpr *expr) {

        VarReference* myvar = dynamic_cast<VarReference*>(expr->getChild(0));
        std::string vars = myvar->identifier()->name();

        VarSymbolTable* table = expr->locateDeclaringTableForVar(vars);
        if (!table) return;

        llvm::Value* varAddr = table->get(vars).LLVMValue;
        if (!varAddr) return;

        Type varType = table->get(vars).VarType;
        if (myvar->isArray()) {
            size_t bound = varType.arrayBound();
            Type::PrimitiveTypeEnum elem = varType.primitiveType();

            myvar->indexExpr()->accept(this);
            llvm::Value* my_index = getExprValue(myvar->indexExpr());
            if (!my_index) return;
            llvm::Type* elemType = getLLVMType(elem);
            llvm::Type* fullArrayTy = getLLVMType(elem, bound);

            std::vector<llvm::Value*> indices;
            indices.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0));
            indices.push_back(my_index);


            llvm::Value* ptr = TheBuilder->CreateGEP(fullArrayTy, varAddr, indices, "arrayidx");
            llvm::Value* loaded = TheBuilder->CreateLoad(elemType, ptr, vars + ".val");
            setExprValue(expr, loaded);

        } else {
            llvm::Type* llvmTy = getLLVMType(varType.primitiveType());
            llvm::Value* loaded = TheBuilder->CreateLoad(llvmTy, varAddr, vars);
            setExprValue(expr, loaded);
        }
    }

    void IRGenerator::visitAssignmentExpr(AssignmentExpr *expr) {
        VarReference* myvar = dynamic_cast<VarReference*>(expr->getChild(0));
        std::string vars = myvar->identifier()->name();

        expr->getChild(1)->accept(this);
        llvm::Value* rhsVal = getExprValue((Expr*)expr->getChild(1));
        if (!rhsVal) return;

        VarSymbolTable* table = expr->locateDeclaringTableForVar(vars);
        if (!table) return;
        llvm::Value* varAddr = table->get(vars).LLVMValue;
        if (!varAddr) return;

        Type varType = table->get(vars).VarType;
        if (myvar->isArray()) {
            size_t bound = varType.arrayBound();
            Type::PrimitiveTypeEnum elem = varType.primitiveType();

            myvar->indexExpr()->accept(this);
            llvm::Value* my_index = getExprValue(myvar->indexExpr());
            if (!my_index) return;

            llvm::Type* elemType = getLLVMType(elem);
            llvm::Type* fullArrayTy = getLLVMType(elem, bound);

            std::vector<llvm::Value*> indices;
            indices.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0));
            indices.push_back(my_index);

            llvm::Value* ptr = TheBuilder->CreateGEP(fullArrayTy, varAddr, indices, "arrayidx");
            TheBuilder->CreateStore(rhsVal, ptr);
        } else {
            TheBuilder->CreateStore(rhsVal, varAddr);
        }

        setExprValue(expr, rhsVal);
    }

    void IRGenerator::visitIntLiteralExpr(IntLiteralExpr *literal) {
        llvm::Value* val = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), literal->value());
        setExprValue(literal, val);
    }

    void IRGenerator::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        llvm::Value* val = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext),literal->value() ? 1 : 0);
        setExprValue(literal, val);
    }

    void IRGenerator::visitCharLiteralExpr(CharLiteralExpr *literal) {
        llvm::Value* val = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*TheContext), literal->value());
        setExprValue(literal, val);
    }
}
