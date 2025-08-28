//
// Created by Fan Long on 2020/12/9.
//

//add more header files if your want
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"
#include <set>
#include <map>
#include "llvm/IR/Constants.h"
#include <vector>

using namespace llvm;

namespace {
    struct Alloca2RegPass : public FunctionPass {
        static char ID;
        Alloca2RegPass() : FunctionPass(ID) {}

        //declare more varibles if you like
        std::set<AllocaInst*> TargetAllocas;
        std::map<BasicBlock*, std::map<AllocaInst*, Value*> > Post;
        std::map<BasicBlock*, std::map<AllocaInst*, PHINode*> > Pre;
        std::map<LoadInst*, AllocaInst*> load_to_alloca_map;
        std::map<StoreInst*, AllocaInst*> store_to_alloca_map;
            int q;

        void collectTargetAllocas(Function &F) {
            //start your code here 
            TargetAllocas.clear();
            load_to_alloca_map.clear();
            store_to_alloca_map.clear();
            std::vector<AllocaInst*> all_stack_vars;
           
            for (Function::iterator  block = F.begin(); block != F.end(); ++block) {
                for (BasicBlock::iterator my_iterator = block->begin(); my_iterator != block->end(); ++my_iterator) {
                    if (AllocaInst *alloca_i = dyn_cast<AllocaInst>(&*my_iterator)) {
                        all_stack_vars.push_back(alloca_i);
                    }
                }
            }
            for (std::vector<AllocaInst*>::iterator alloca_i = all_stack_vars.begin(); alloca_i != all_stack_vars.end(); ++alloca_i) {
                if ((*alloca_i)->getAllocatedType()->isArrayTy()) {
                    continue;

                }
                
                bool promotable = true;
                for (Function::iterator block = F.begin(); block != F.end(); ++block) {
                    for (BasicBlock::iterator my_iterator = block->begin(); my_iterator != block->end(); ++my_iterator) {
                        if (LoadInst *load_i = dyn_cast<LoadInst>(&*my_iterator)) {
                            if (load_i->getPointerOperand() == *alloca_i) {
                                load_to_alloca_map[load_i] = *alloca_i; 
                            }
                        }
                    }
                }
                for (Function::iterator block = F.begin(); block != F.end(); ++block) {
                    for (BasicBlock::iterator my_iterator = block->begin(); my_iterator != block->end(); ++my_iterator) {
                        if (StoreInst *curr = dyn_cast<StoreInst>(&*my_iterator)) {
                            if (curr->getPointerOperand() == *alloca_i) {
                                store_to_alloca_map[curr] = *alloca_i;
                            }
                        }
                    }
                }
                
                for (Function::iterator block = F.begin(); block != F.end(); ++block) {
                    for (BasicBlock::iterator my_iterator = block->begin(); my_iterator != block->end(); ++my_iterator)  {
                        if (!isa<LoadInst>(*my_iterator) && !isa<StoreInst>(*my_iterator)) {
                            for (Use &use_var : my_iterator->operands()) {
                                if (use_var.get() == *alloca_i) {
                                    promotable = false; 
                                    break;
                                }
                            }
                        }

                        if (!promotable) {
                            break;
                        }
                    }
                    if (!promotable) {
                        break;
                    }
                }
                if (promotable) {
                    TargetAllocas.insert(*alloca_i);
                }
            }
        }





        void stepOne(Function &F) {
            for (Function::iterator block = F.begin(); block != F.end(); ++block) {
                Post[&*block] = std::map<AllocaInst*,  Value*>();
                if (&*block == &F.getEntryBlock()) {
                    for (std::set<AllocaInst*>::iterator alloca_i = TargetAllocas.begin(); alloca_i != TargetAllocas.end(); ++alloca_i) {
                        Post[&*block][*alloca_i] = UndefValue::get((*alloca_i)->getAllocatedType());
                    }
                }
            }
            
            for (Function::iterator block = F.begin(); block != F.end(); ++block) {
                if (&*block == &F.getEntryBlock()) {
                    continue;
                }
                unsigned predecessor_count = 0;
                for (pred_iterator my_pi = pred_begin(&*block); my_pi != pred_end(&*block); ++my_pi) {
                    predecessor_count++;
                }
                
                for (std::set<AllocaInst*>::iterator alloca_i= TargetAllocas.begin(); alloca_i != TargetAllocas.end(); ++alloca_i) {
                    PHINode *phi_node = PHINode::Create((*alloca_i)->getAllocatedType(), predecessor_count, (*alloca_i)->getName() + ".phi",&(block->front()));
                    Pre[&*block][*alloca_i] = phi_node;
                    Post[&*block][*alloca_i] = phi_node;
                }
            }
        }
        

        void stepTwo(Function &F) {
            for (Function::iterator block = F.begin(); block != F.end(); ++block) {

                std::map<AllocaInst*, Value*> block_values;

                if (Post.find(&*block) != Post.end()) {
                    for (std::map<AllocaInst*, Value*>::iterator val = Post[&*block].begin(); val != Post[&*block].end(); ++val) {
                        block_values[val->first] = val->second;
                    }
                }
                for (BasicBlock::iterator my_iterator = block->begin(); my_iterator != block->end(); ++my_iterator) {
                    if (LoadInst *load_i = dyn_cast<LoadInst>(&*my_iterator)) {
                        std::map<LoadInst*, AllocaInst*>::iterator my_iterator = load_to_alloca_map.find(load_i);
                        if (my_iterator != load_to_alloca_map.end()) {
                            AllocaInst *alloca_i = my_iterator->second;
                            if (TargetAllocas.count(alloca_i)) {
                                std::map<AllocaInst*, Value*>::iterator value_it = block_values.find(alloca_i);
                                if (value_it != block_values.end()) {
                                    Value *val = value_it->second;
                                    if (val) {
                                        load_i->replaceAllUsesWith(val);
                                    }
                                }

                            }
                        }
                    } else if (StoreInst *curr = dyn_cast<StoreInst>(&*my_iterator)) {
                        std::map<StoreInst*, AllocaInst*>::iterator my_iterator = store_to_alloca_map.find(curr);
                        if (my_iterator != store_to_alloca_map.end()) {
                            AllocaInst *alloca_i = my_iterator->second;
                            if (TargetAllocas.count(alloca_i)) {
                                block_values[alloca_i] =curr->getValueOperand();
                            }
                         }
                    }
                }
                
                Post[&*block] = block_values;
            }
        }

        void stepThree(Function &F) {

            for (std::map<BasicBlock*, std::map<AllocaInst*, PHINode*>>::iterator entry = Pre.begin(); entry != Pre.end(); ++entry) {
                BasicBlock *block = entry->first;
                std::map<AllocaInst*, PHINode*> &alloca_phis = entry->second;
                
                for (std::map<AllocaInst*, PHINode*>::iterator phi_entry = alloca_phis.begin(); phi_entry != alloca_phis.end(); ++phi_entry) {
                    AllocaInst *alloca_i = phi_entry->first;
                    PHINode *phi_node = phi_entry->second; 
                    for (pred_iterator pred_i = pred_begin(block); pred_i != pred_end(block); ++pred_i) {
                        BasicBlock *pred = *pred_i;
                        
                        bool edge_exists = false;
                        for (unsigned i = 0; i < phi_node->getNumIncomingValues(); i++) {
                            if (phi_node->getIncomingBlock(i) == pred) {
                                edge_exists = true;
                                break;
                            }
                        }
                        
                        if (!edge_exists) {
                            Value *value_from_predecessor = nullptr;
                            
                            if (Post.find(pred) != Post.end() && 
                                Post[pred].find(alloca_i) != Post[pred].end()) {
                                value_from_predecessor = Post[pred][alloca_i];
                            }

                            if (!value_from_predecessor) {
                                value_from_predecessor = UndefValue::get(alloca_i->getAllocatedType());
                            }
                            
                            phi_node->addIncoming(value_from_predecessor, pred);
                        }
                    }
                }
            }
        }

        void stepFour(Function &F) {
            bool changes_made = true;

            while (changes_made) {
                changes_made = false;
                
                std::map<BasicBlock*, std::map<AllocaInst*, PHINode*>> current_phi_nodes = Pre;
                
                for (std::map<BasicBlock*, std::map<AllocaInst*, PHINode*>>::iterator entry = current_phi_nodes.begin(); entry != current_phi_nodes.end(); ++entry) {
                    BasicBlock *block = entry->first;
                    std::map<AllocaInst*, PHINode*> &alloca_phis = entry->second;
                    
                    for (std::map<AllocaInst*, PHINode*>::iterator phi_entry = alloca_phis.begin(); phi_entry != alloca_phis.end(); ++phi_entry) {
                        AllocaInst *alloca_i = phi_entry->first;
                        PHINode *phi_node = phi_entry->second;
                        
                        Value *common_value = nullptr;
                        bool has_identical_values = true;
                        
                        for (unsigned i = 0; i < phi_node->getNumIncomingValues(); i++) {
                            Value *in_val = phi_node->getIncomingValue(i);
                            
                            if (in_val == phi_node) {
                                continue;
                            }
                            
                            if (!common_value) {
                                common_value = in_val;
                            } else if (common_value != in_val) {
                                has_identical_values = false; 
                                break;
                            }
                        }
                        
                        if (has_identical_values && common_value) {
                            phi_node->replaceAllUsesWith(common_value);
                            Post[block][alloca_i] = common_value; 
                             phi_node->eraseFromParent(); 
                            Pre[block].erase(alloca_i);
                            changes_made = true;
                        }
                    } 
                }
            }
            
            std::vector<Instruction*> dead_load_instructions;
            std::vector<Instruction*> dead_store_instructions;
            std::vector<AllocaInst*> dead_alloca_instructions;

            for (Function::iterator block = F.begin(); block != F.end(); ++block) {

                for (BasicBlock::iterator my_iterator = block->begin(); my_iterator != block->end(); ++my_iterator) {

                    if (LoadInst *load_i = dyn_cast<LoadInst>(&*my_iterator)) {
                        Value *ptr = load_i->getPointerOperand();

                        if (AllocaInst *alloca_i = dyn_cast<AllocaInst>(ptr)) {
                            if (TargetAllocas.count(alloca_i) && load_i->use_empty()) {
                                dead_load_instructions.push_back(load_i);
                            }

                        }
                    } else if (StoreInst *store_i = dyn_cast<StoreInst>(&*my_iterator )) {
                        Value *ptr = store_i->getPointerOperand();
                        if (AllocaInst *alloca_i = dyn_cast<AllocaInst>(ptr)) {
                            if (TargetAllocas.count(alloca_i)) {
                                dead_store_instructions.push_back(store_i); 
                            }
                            
                        }

                    } else if (AllocaInst *alloca_i = dyn_cast<AllocaInst>(&*my_iterator)) {
                        if (TargetAllocas.count(alloca_i)) {
                            dead_alloca_instructions.push_back(alloca_i);
                        }
                    }
                }
            }

            for (std::vector<Instruction*>::iterator my_iterator = dead_load_instructions.begin(); my_iterator != dead_load_instructions.end(); ++my_iterator) {
                (*my_iterator)->eraseFromParent();
            }
            
            for (std::vector<Instruction*>::iterator my_iterator = dead_store_instructions.begin(); my_iterator != dead_store_instructions.end(); ++my_iterator) {
                (*my_iterator)->eraseFromParent();
            }
            for (std::vector<AllocaInst*>::iterator alloca_i = dead_alloca_instructions.begin(); alloca_i != dead_alloca_instructions.end(); ++alloca_i) {
                (*alloca_i)->eraseFromParent();
        }
        }




        virtual bool runOnFunction(Function &F) {
            errs() << "Working on function called " << F.getName() << "!\n";
            collectTargetAllocas(F);
            //start your code here

            collectTargetAllocas(F);
            stepOne(F);
            stepTwo(F);
            stepThree(F);
            stepFour(F);
            
            bool modified = !TargetAllocas.empty() && !F.empty();
            return modified;
            //return true;



        }
    };
}

char Alloca2RegPass::ID = 0;

static RegisterPass<Alloca2RegPass> X("alloca2reg", "Alloca-to-register pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAlloca2RegPass(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new Alloca2RegPass());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerAlloca2RegPass);
