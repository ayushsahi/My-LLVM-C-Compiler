
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
#include <iostream>


// Generated from MiniC.g4 by ANTLR 4.7.2


#include "MiniCListener.h"

#include "MiniCParser.h"


using namespace antlrcpp;
using namespace antlr4;

MiniCParser::MiniCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MiniCParser::~MiniCParser() {
  delete _interpreter;
}

std::string MiniCParser::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MiniCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

MiniCParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ProgContext::EOF() {
  return getToken(MiniCParser::EOF, 0);
}

MiniCParser::PreambleContext* MiniCParser::ProgContext::preamble() {
  return getRuleContext<MiniCParser::PreambleContext>(0);
}

std::vector<MiniCParser::DeclContext *> MiniCParser::ProgContext::decl() {
  return getRuleContexts<MiniCParser::DeclContext>();
}

MiniCParser::DeclContext* MiniCParser::ProgContext::decl(size_t i) {
  return getRuleContext<MiniCParser::DeclContext>(i);
}


size_t MiniCParser::ProgContext::getRuleIndex() const {
  return MiniCParser::RuleProg;
}

void MiniCParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void MiniCParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

MiniCParser::ProgContext* MiniCParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniCParser::RuleProg);

      dynamic_cast<ProgContext *>(_localctx)->val =  new minicc::Program();
      _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__0: {
        setState(42);
        preamble();
         _localctx->val->setSyslibFlag(true); 
        break;
      }

      case MiniCParser::EOF:
      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18:
      case MiniCParser::T__19: {
         _localctx->val->setSyslibFlag(false); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::T__16)
      | (1ULL << MiniCParser::T__17)
      | (1ULL << MiniCParser::T__18)
      | (1ULL << MiniCParser::T__19))) != 0)) {
      setState(48);
      dynamic_cast<ProgContext *>(_localctx)->declContext = decl();
      _localctx->val->addChild(dynamic_cast<ProgContext *>(_localctx)->declContext->val); 
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    match(MiniCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

MiniCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::PreambleContext::getRuleIndex() const {
  return MiniCParser::RulePreamble;
}

void MiniCParser::PreambleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreamble(this);
}

void MiniCParser::PreambleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreamble(this);
}

MiniCParser::PreambleContext* MiniCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniCParser::RulePreamble);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(MiniCParser::T__0);
    setState(59);
    match(MiniCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

MiniCParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VardeclContext* MiniCParser::DeclContext::vardecl() {
  return getRuleContext<MiniCParser::VardeclContext>(0);
}

MiniCParser::RettypeContext* MiniCParser::DeclContext::rettype() {
  return getRuleContext<MiniCParser::RettypeContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::DeclContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ParametersContext* MiniCParser::DeclContext::parameters() {
  return getRuleContext<MiniCParser::ParametersContext>(0);
}

MiniCParser::ScopeContext* MiniCParser::DeclContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}


size_t MiniCParser::DeclContext::getRuleIndex() const {
  return MiniCParser::RuleDecl;
}

void MiniCParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void MiniCParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

MiniCParser::DeclContext* MiniCParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, MiniCParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61);
      dynamic_cast<DeclContext *>(_localctx)->vardeclContext = vardecl();
      dynamic_cast<DeclContext *>(_localctx)->val =  dynamic_cast<DeclContext *>(_localctx)->vardeclContext->val; 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      dynamic_cast<DeclContext *>(_localctx)->rettypeContext = rettype();
      setState(65);
      dynamic_cast<DeclContext *>(_localctx)->funcnameContext = funcname();
      setState(66);
      match(MiniCParser::T__2);
      setState(67);
      dynamic_cast<DeclContext *>(_localctx)->parametersContext = parameters();
      setState(68);
      match(MiniCParser::T__3);
      setState(69);
      dynamic_cast<DeclContext *>(_localctx)->scopeContext = scope();

                  dynamic_cast<DeclContext *>(_localctx)->func =  new minicc::FuncDeclaration();
                  _localctx->func->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                  _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->rettypeContext->val);
                  _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->funcnameContext->val);
                  for (size_t i = 0; i < dynamic_cast<DeclContext *>(_localctx)->parametersContext->val.size(); i++)
                      _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->parametersContext->val[i]);
                  _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->scopeContext->val);
                  _localctx->func->setHasBody(true);
                  dynamic_cast<DeclContext *>(_localctx)->val =  _localctx->func;
              
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(72);
      dynamic_cast<DeclContext *>(_localctx)->rettypeContext = rettype();
      setState(73);
      dynamic_cast<DeclContext *>(_localctx)->funcnameContext = funcname();
      setState(74);
      match(MiniCParser::T__2);
      setState(75);
      dynamic_cast<DeclContext *>(_localctx)->parametersContext = parameters();
      setState(76);
      match(MiniCParser::T__3);
      setState(77);
      match(MiniCParser::T__4);

                  dynamic_cast<DeclContext *>(_localctx)->func =  new minicc::FuncDeclaration();
                  _localctx->func->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                  _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->rettypeContext->val);
                  _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->funcnameContext->val);
                  for (size_t i = 0; i < dynamic_cast<DeclContext *>(_localctx)->parametersContext->val.size(); i++)
                      _localctx->func->addChild(dynamic_cast<DeclContext *>(_localctx)->parametersContext->val[i]);
                  _localctx->func->setHasBody(false);
                  dynamic_cast<DeclContext *>(_localctx)->val =  _localctx->func;
              
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

MiniCParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::VardeclContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::VarlistContext* MiniCParser::VardeclContext::varlist() {
  return getRuleContext<MiniCParser::VarlistContext>(0);
}


size_t MiniCParser::VardeclContext::getRuleIndex() const {
  return MiniCParser::RuleVardecl;
}

void MiniCParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void MiniCParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}

MiniCParser::VardeclContext* MiniCParser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniCParser::RuleVardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    dynamic_cast<VardeclContext *>(_localctx)->vartypeContext = vartype();
    setState(83);
    dynamic_cast<VardeclContext *>(_localctx)->varlistContext = varlist(0);
    setState(84);
    match(MiniCParser::T__4);

            dynamic_cast<VardeclContext *>(_localctx)->val =  new minicc::VarDeclaration();
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            _localctx->val->addChild(dynamic_cast<VardeclContext *>(_localctx)->vartypeContext->val);
            for (size_t i = 0; i < dynamic_cast<VardeclContext *>(_localctx)->varlistContext->val.size(); i++)
                _localctx->val->addChild(dynamic_cast<VardeclContext *>(_localctx)->varlistContext->val[i]);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

MiniCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniCParser::VardeclContext *> MiniCParser::ScopeContext::vardecl() {
  return getRuleContexts<MiniCParser::VardeclContext>();
}

MiniCParser::VardeclContext* MiniCParser::ScopeContext::vardecl(size_t i) {
  return getRuleContext<MiniCParser::VardeclContext>(i);
}

std::vector<MiniCParser::StmtContext *> MiniCParser::ScopeContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::ScopeContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}


size_t MiniCParser::ScopeContext::getRuleIndex() const {
  return MiniCParser::RuleScope;
}

void MiniCParser::ScopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScope(this);
}

void MiniCParser::ScopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScope(this);
}

MiniCParser::ScopeContext* MiniCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 8, MiniCParser::RuleScope);

      dynamic_cast<ScopeContext *>(_localctx)->val =  new minicc::ScopeStatement();
      _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
      dynamic_cast<ScopeContext *>(_localctx)->declcnt =  0;

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(MiniCParser::T__5);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::T__16)
      | (1ULL << MiniCParser::T__17)
      | (1ULL << MiniCParser::T__18))) != 0)) {
      setState(88);
      dynamic_cast<ScopeContext *>(_localctx)->vardeclContext = vardecl();

              _localctx->val->addChild(dynamic_cast<ScopeContext *>(_localctx)->vardeclContext->val);
              _localctx->declcnt ++;
          
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::T__2)
      | (1ULL << MiniCParser::T__5)
      | (1ULL << MiniCParser::T__7)
      | (1ULL << MiniCParser::T__9)
      | (1ULL << MiniCParser::T__10)
      | (1ULL << MiniCParser::T__11)
      | (1ULL << MiniCParser::T__12)
      | (1ULL << MiniCParser::T__20)
      | (1ULL << MiniCParser::T__30)
      | (1ULL << MiniCParser::T__34)
      | (1ULL << MiniCParser::T__35)
      | (1ULL << MiniCParser::ID)
      | (1ULL << MiniCParser::INT)
      | (1ULL << MiniCParser::CHAR))) != 0)) {
      setState(96);
      dynamic_cast<ScopeContext *>(_localctx)->stmtContext = stmt();

              _localctx->val->addChild(dynamic_cast<ScopeContext *>(_localctx)->stmtContext->val);
          
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(104);
    match(MiniCParser::T__6);

            _localctx->val->setNumVarDecl(_localctx->declcnt);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

MiniCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::StmtContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::StmtContext *> MiniCParser::StmtContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::StmtContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}

std::vector<MiniCParser::ExproptContext *> MiniCParser::StmtContext::expropt() {
  return getRuleContexts<MiniCParser::ExproptContext>();
}

MiniCParser::ExproptContext* MiniCParser::StmtContext::expropt(size_t i) {
  return getRuleContext<MiniCParser::ExproptContext>(i);
}

MiniCParser::ScopeContext* MiniCParser::StmtContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}


size_t MiniCParser::StmtContext::getRuleIndex() const {
  return MiniCParser::RuleStmt;
}

void MiniCParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void MiniCParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

MiniCParser::StmtContext* MiniCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 10, MiniCParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(108);
      match(MiniCParser::T__4);

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::ExprStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(MiniCParser::T__7);
      setState(112);
      match(MiniCParser::T__2);
      setState(113);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(114);
      match(MiniCParser::T__3);
      setState(115);
      dynamic_cast<StmtContext *>(_localctx)->stmtContext = stmt();

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::IfStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->exprContext->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->stmtContext->val);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(118);
      match(MiniCParser::T__7);
      setState(119);
      match(MiniCParser::T__2);
      setState(120);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(121);
      match(MiniCParser::T__3);
      setState(122);
      dynamic_cast<StmtContext *>(_localctx)->s1 = stmt();
      setState(123);
      match(MiniCParser::T__8);
      setState(124);
      dynamic_cast<StmtContext *>(_localctx)->s2 = stmt();

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::IfStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->exprContext->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->s1->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->s2->val);
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(127);
      match(MiniCParser::T__9);
      setState(128);
      match(MiniCParser::T__2);
      setState(129);
      dynamic_cast<StmtContext *>(_localctx)->e1 = expropt();
      setState(130);
      match(MiniCParser::T__4);
      setState(131);
      dynamic_cast<StmtContext *>(_localctx)->e2 = expropt();
      setState(132);
      match(MiniCParser::T__4);
      setState(133);
      dynamic_cast<StmtContext *>(_localctx)->e3 = expropt();
      setState(134);
      match(MiniCParser::T__3);
      setState(135);
      dynamic_cast<StmtContext *>(_localctx)->stmtContext = stmt();

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::ForStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->e1->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->e2->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->e3->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->stmtContext->val);
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(138);
      match(MiniCParser::T__10);
      setState(139);
      match(MiniCParser::T__2);
      setState(140);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(141);
      match(MiniCParser::T__3);
      setState(142);
      dynamic_cast<StmtContext *>(_localctx)->stmtContext = stmt();

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::WhileStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->exprContext->val);
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->stmtContext->val);
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(145);
      match(MiniCParser::T__11);
      setState(146);
      match(MiniCParser::T__4);

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::BreakStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(148);
      match(MiniCParser::T__12);
      setState(149);
      match(MiniCParser::T__4);

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::ReturnStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(151);
      match(MiniCParser::T__12);
      setState(152);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(153);
      match(MiniCParser::T__4);

              dynamic_cast<StmtContext *>(_localctx)->val =  new minicc::ReturnStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<StmtContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(156);
      dynamic_cast<StmtContext *>(_localctx)->scopeContext = scope();

              dynamic_cast<StmtContext *>(_localctx)->val =  dynamic_cast<StmtContext *>(_localctx)->scopeContext->val;
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarlistContext ------------------------------------------------------------------

MiniCParser::VarlistContext::VarlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarlistentryContext* MiniCParser::VarlistContext::varlistentry() {
  return getRuleContext<MiniCParser::VarlistentryContext>(0);
}

MiniCParser::VarlistContext* MiniCParser::VarlistContext::varlist() {
  return getRuleContext<MiniCParser::VarlistContext>(0);
}


size_t MiniCParser::VarlistContext::getRuleIndex() const {
  return MiniCParser::RuleVarlist;
}

void MiniCParser::VarlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlist(this);
}

void MiniCParser::VarlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlist(this);
}


MiniCParser::VarlistContext* MiniCParser::varlist() {
   return varlist(0);
}

MiniCParser::VarlistContext* MiniCParser::varlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::VarlistContext *_localctx = _tracker.createInstance<VarlistContext>(_ctx, parentState);
  MiniCParser::VarlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, MiniCParser::RuleVarlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(162);
    dynamic_cast<VarlistContext *>(_localctx)->varlistentryContext = varlistentry();

            _localctx->val.clear();
            _localctx->val.push_back(dynamic_cast<VarlistContext *>(_localctx)->varlistentryContext->val);
        
    _ctx->stop = _input->LT(-1);
    setState(172);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VarlistContext>(parentContext, parentState);
        _localctx->v1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleVarlist);
        setState(165);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(166);
        match(MiniCParser::T__13);
        setState(167);
        dynamic_cast<VarlistContext *>(_localctx)->varlistentryContext = varlistentry();

                          dynamic_cast<VarlistContext *>(_localctx)->val =  dynamic_cast<VarlistContext *>(_localctx)->v1->val;
                          _localctx->val.push_back(dynamic_cast<VarlistContext *>(_localctx)->varlistentryContext->val);
                       
      }
      setState(174);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarlistentryContext ------------------------------------------------------------------

MiniCParser::VarlistentryContext::VarlistentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarlistentryContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

tree::TerminalNode* MiniCParser::VarlistentryContext::INT() {
  return getToken(MiniCParser::INT, 0);
}


size_t MiniCParser::VarlistentryContext::getRuleIndex() const {
  return MiniCParser::RuleVarlistentry;
}

void MiniCParser::VarlistentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlistentry(this);
}

void MiniCParser::VarlistentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlistentry(this);
}

MiniCParser::VarlistentryContext* MiniCParser::varlistentry() {
  VarlistentryContext *_localctx = _tracker.createInstance<VarlistentryContext>(_ctx, getState());
  enterRule(_localctx, 14, MiniCParser::RuleVarlistentry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(175);
      dynamic_cast<VarlistentryContext *>(_localctx)->varnameContext = varname();

              dynamic_cast<VarlistentryContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<VarlistentryContext *>(_localctx)->varnameContext->val);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(178);
      dynamic_cast<VarlistentryContext *>(_localctx)->varnameContext = varname();
      setState(179);
      match(MiniCParser::T__14);
      setState(180);
      dynamic_cast<VarlistentryContext *>(_localctx)->intToken = match(MiniCParser::INT);
      setState(181);
      match(MiniCParser::T__15);

              dynamic_cast<VarlistentryContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<VarlistentryContext *>(_localctx)->varnameContext->val);
              dynamic_cast<VarlistentryContext *>(_localctx)->tmp =  minicc::ConstantLiteralExpr::fromString((dynamic_cast<VarlistentryContext *>(_localctx)->intToken != nullptr ? dynamic_cast<VarlistentryContext *>(_localctx)->intToken->getText() : ""));
              _localctx->tmp->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(_localctx->tmp);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

MiniCParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::VartypeContext::getRuleIndex() const {
  return MiniCParser::RuleVartype;
}

void MiniCParser::VartypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVartype(this);
}

void MiniCParser::VartypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVartype(this);
}

MiniCParser::VartypeContext* MiniCParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniCParser::RuleVartype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        match(MiniCParser::T__16);

                dynamic_cast<VartypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Int);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case MiniCParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(188);
        match(MiniCParser::T__17);

                dynamic_cast<VartypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Bool);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 3);
        setState(190);
        match(MiniCParser::T__18);

                dynamic_cast<VartypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Char);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RettypeContext ------------------------------------------------------------------

MiniCParser::RettypeContext::RettypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::RettypeContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}


size_t MiniCParser::RettypeContext::getRuleIndex() const {
  return MiniCParser::RuleRettype;
}

void MiniCParser::RettypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRettype(this);
}

void MiniCParser::RettypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRettype(this);
}

MiniCParser::RettypeContext* MiniCParser::rettype() {
  RettypeContext *_localctx = _tracker.createInstance<RettypeContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniCParser::RuleRettype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        match(MiniCParser::T__19);

                dynamic_cast<RettypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Void);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(196);
        dynamic_cast<RettypeContext *>(_localctx)->vartypeContext = vartype();

                dynamic_cast<RettypeContext *>(_localctx)->val =  dynamic_cast<RettypeContext *>(_localctx)->vartypeContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

MiniCParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ParameterlistContext* MiniCParser::ParametersContext::parameterlist() {
  return getRuleContext<MiniCParser::ParameterlistContext>(0);
}


size_t MiniCParser::ParametersContext::getRuleIndex() const {
  return MiniCParser::RuleParameters;
}

void MiniCParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void MiniCParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

MiniCParser::ParametersContext* MiniCParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 20, MiniCParser::RuleParameters);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

                _localctx->val.clear();
            
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(202);
        dynamic_cast<ParametersContext *>(_localctx)->parameterlistContext = parameterlist(0);

                dynamic_cast<ParametersContext *>(_localctx)->val =  dynamic_cast<ParametersContext *>(_localctx)->parameterlistContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterlistContext ------------------------------------------------------------------

MiniCParser::ParameterlistContext::ParameterlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ParameterentryContext* MiniCParser::ParameterlistContext::parameterentry() {
  return getRuleContext<MiniCParser::ParameterentryContext>(0);
}

MiniCParser::ParameterlistContext* MiniCParser::ParameterlistContext::parameterlist() {
  return getRuleContext<MiniCParser::ParameterlistContext>(0);
}


size_t MiniCParser::ParameterlistContext::getRuleIndex() const {
  return MiniCParser::RuleParameterlist;
}

void MiniCParser::ParameterlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterlist(this);
}

void MiniCParser::ParameterlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterlist(this);
}


MiniCParser::ParameterlistContext* MiniCParser::parameterlist() {
   return parameterlist(0);
}

MiniCParser::ParameterlistContext* MiniCParser::parameterlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ParameterlistContext *_localctx = _tracker.createInstance<ParameterlistContext>(_ctx, parentState);
  MiniCParser::ParameterlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, MiniCParser::RuleParameterlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(208);
    dynamic_cast<ParameterlistContext *>(_localctx)->parameterentryContext = parameterentry();

            _localctx->val.clear();
            _localctx->val.push_back(dynamic_cast<ParameterlistContext *>(_localctx)->parameterentryContext->val);
        
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterlistContext>(parentContext, parentState);
        _localctx->p1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleParameterlist);
        setState(211);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(212);
        match(MiniCParser::T__13);
        setState(213);
        dynamic_cast<ParameterlistContext *>(_localctx)->parameterentryContext = parameterentry();

                          dynamic_cast<ParameterlistContext *>(_localctx)->val = dynamic_cast<ParameterlistContext *>(_localctx)->p1->val;
                          _localctx->val.push_back(dynamic_cast<ParameterlistContext *>(_localctx)->parameterentryContext->val);
                       
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterentryContext ------------------------------------------------------------------

MiniCParser::ParameterentryContext::ParameterentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::ParameterentryContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ParameterentryContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}


size_t MiniCParser::ParameterentryContext::getRuleIndex() const {
  return MiniCParser::RuleParameterentry;
}

void MiniCParser::ParameterentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterentry(this);
}

void MiniCParser::ParameterentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterentry(this);
}

MiniCParser::ParameterentryContext* MiniCParser::parameterentry() {
  ParameterentryContext *_localctx = _tracker.createInstance<ParameterentryContext>(_ctx, getState());
  enterRule(_localctx, 24, MiniCParser::RuleParameterentry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    dynamic_cast<ParameterentryContext *>(_localctx)->vartypeContext = vartype();
    setState(222);
    dynamic_cast<ParameterentryContext *>(_localctx)->parameternameContext = parametername();

            dynamic_cast<ParameterentryContext *>(_localctx)->val =  new minicc::Parameter();
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            _localctx->val->addChild(dynamic_cast<ParameterentryContext *>(_localctx)->vartypeContext->val);
            _localctx->val->addChild(dynamic_cast<ParameterentryContext *>(_localctx)->parameternameContext->val);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExproptContext ------------------------------------------------------------------

MiniCParser::ExproptContext::ExproptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ExproptContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::ExproptContext::getRuleIndex() const {
  return MiniCParser::RuleExpropt;
}

void MiniCParser::ExproptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpropt(this);
}

void MiniCParser::ExproptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpropt(this);
}

MiniCParser::ExproptContext* MiniCParser::expropt() {
  ExproptContext *_localctx = _tracker.createInstance<ExproptContext>(_ctx, getState());
  enterRule(_localctx, 26, MiniCParser::RuleExpropt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__2:
      case MiniCParser::T__20:
      case MiniCParser::T__30:
      case MiniCParser::T__34:
      case MiniCParser::T__35:
      case MiniCParser::ID:
      case MiniCParser::INT:
      case MiniCParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(225);
        dynamic_cast<ExproptContext *>(_localctx)->exprContext = expr(0);

                dynamic_cast<ExproptContext *>(_localctx)->val =  dynamic_cast<ExproptContext *>(_localctx)->exprContext->val;
            
        break;
      }

      case MiniCParser::T__3:
      case MiniCParser::T__4: {
        enterOuterAlt(_localctx, 2);

                dynamic_cast<ExproptContext *>(_localctx)->val =  nullptr;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MiniCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ExprContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

tree::TerminalNode* MiniCParser::ExprContext::CHAR() {
  return getToken(MiniCParser::CHAR, 0);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::ExprContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::ExprContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}

MiniCParser::VarContext* MiniCParser::ExprContext::var() {
  return getRuleContext<MiniCParser::VarContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::ExprContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ArgumentsContext* MiniCParser::ExprContext::arguments() {
  return getRuleContext<MiniCParser::ArgumentsContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ExprContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}


size_t MiniCParser::ExprContext::getRuleIndex() const {
  return MiniCParser::RuleExpr;
}

void MiniCParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void MiniCParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


MiniCParser::ExprContext* MiniCParser::expr() {
   return expr(0);
}

MiniCParser::ExprContext* MiniCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MiniCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, MiniCParser::RuleExpr, precedence);

    dynamic_cast<ExprContext *>(_localctx)->minus_flag = false; dynamic_cast<ExprContext *>(_localctx)->compare = false;
    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(232);
      dynamic_cast<ExprContext *>(_localctx)->intToken = match(MiniCParser::INT);

              dynamic_cast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString((dynamic_cast<ExprContext *>(_localctx)->intToken != nullptr ? dynamic_cast<ExprContext *>(_localctx)->intToken->getText() : ""));
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      setState(234);
      dynamic_cast<ExprContext *>(_localctx)->charToken = match(MiniCParser::CHAR);

              dynamic_cast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString((dynamic_cast<ExprContext *>(_localctx)->charToken != nullptr ? dynamic_cast<ExprContext *>(_localctx)->charToken->getText() : ""));
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 3: {
      setState(236);
      match(MiniCParser::T__20);
      setState(237);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(14);

              dynamic_cast<ExprContext *>(_localctx)->minus_flag =  true;
              if (typeid(*dynamic_cast<ExprContext *>(_localctx)->exprContext->val) == typeid(minicc::IntLiteralExpr)){
                  delete dynamic_cast<ExprContext *>(_localctx)->exprContext->val;
                  dynamic_cast<ExprContext *>(_localctx)->exprContext->val = minicc::ConstantLiteralExpr::fromString((dynamic_cast<ExprContext *>(_localctx)->exprContext != nullptr ? _input->getText(dynamic_cast<ExprContext *>(_localctx)->exprContext->start, dynamic_cast<ExprContext *>(_localctx)->exprContext->stop) : nullptr), _localctx->minus_flag);
                  dynamic_cast<ExprContext *>(_localctx)->exprContext->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine()); 
              }
              dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::UnaryExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              ((minicc::UnaryExpr*)_localctx->val)->setOpcode(minicc::Expr::Sub);
              _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 4: {
      setState(240);
      match(MiniCParser::T__30);
      setState(241);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(10);

              dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::UnaryExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              ((minicc::UnaryExpr*)_localctx->val)->setOpcode(minicc::Expr::Not);
              _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 5: {
      setState(244);
      dynamic_cast<ExprContext *>(_localctx)->varContext = var();
      setState(245);
      match(MiniCParser::T__33);
      setState(246);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(7);

              dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::AssignmentExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->varContext->val);
              _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 6: {
      setState(249);
      match(MiniCParser::T__34);

              dynamic_cast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString("true");
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 7: {
      setState(251);
      match(MiniCParser::T__35);

              dynamic_cast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString("false");
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 8: {
      setState(253);
      match(MiniCParser::T__2);
      setState(254);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(255);
      match(MiniCParser::T__3);

              dynamic_cast<ExprContext *>(_localctx)->val =  dynamic_cast<ExprContext *>(_localctx)->exprContext->val;
          
      break;
    }

    case 9: {
      setState(258);
      dynamic_cast<ExprContext *>(_localctx)->varContext = var();

              dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::VarExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->varContext->val);
          
      break;
    }

    case 10: {
      setState(261);
      dynamic_cast<ExprContext *>(_localctx)->funcnameContext = funcname();
      setState(262);
      match(MiniCParser::T__2);
      setState(263);
      dynamic_cast<ExprContext *>(_localctx)->argumentsContext = arguments();
      setState(264);
      match(MiniCParser::T__3);

              dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::CallExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->funcnameContext->val);
              for (size_t i = 0; i < dynamic_cast<ExprContext *>(_localctx)->argumentsContext->val.size(); i++)
                  _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->argumentsContext->val[i]);
          
      break;
    }

    case 11: {
      setState(267);
      dynamic_cast<ExprContext *>(_localctx)->parameternameContext = parametername();

              dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::VarExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              dynamic_cast<ExprContext *>(_localctx)->tmp =  new minicc::VarReference();
              _localctx->tmp->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->tmp->addChild(dynamic_cast<ExprContext *>(_localctx)->parameternameContext->val);
              _localctx->val->addChild(_localctx->tmp);
          
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(297);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(272);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(273);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniCParser::T__21

          || _la == MiniCParser::T__22)) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(274);
          dynamic_cast<ExprContext *>(_localctx)->e2 = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(14);

                            dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::opcodeFromString((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : "")));
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(277);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(278);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniCParser::T__20

          || _la == MiniCParser::T__23)) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(279);
          dynamic_cast<ExprContext *>(_localctx)->e2 = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(13);

                            dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::opcodeFromString((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : "")));
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(282);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(283);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MiniCParser::T__24)
            | (1ULL << MiniCParser::T__25)
            | (1ULL << MiniCParser::T__26)
            | (1ULL << MiniCParser::T__27)
            | (1ULL << MiniCParser::T__28)
            | (1ULL << MiniCParser::T__29))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(284);
          dynamic_cast<ExprContext *>(_localctx)->e2 = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(12);

                            dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            dynamic_cast<ExprContext *>(_localctx)->compare =  true;
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::opcodeFromString((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : "")));
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(287);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(288);
          match(MiniCParser::T__31);
          setState(289);
          dynamic_cast<ExprContext *>(_localctx)->e2 = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(10);

                            dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::And);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(292);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(293);
          match(MiniCParser::T__32);
          setState(294);
          dynamic_cast<ExprContext *>(_localctx)->e2 = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(9);

                            dynamic_cast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::Or);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(dynamic_cast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        } 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

MiniCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

MiniCParser::ExprContext* MiniCParser::VarContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::VarContext::getRuleIndex() const {
  return MiniCParser::RuleVar;
}

void MiniCParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void MiniCParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}

MiniCParser::VarContext* MiniCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 30, MiniCParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(302);
      dynamic_cast<VarContext *>(_localctx)->varnameContext = varname();

              dynamic_cast<VarContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<VarContext *>(_localctx)->varnameContext->val);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(305);
      dynamic_cast<VarContext *>(_localctx)->varnameContext = varname();
      setState(306);
      match(MiniCParser::T__14);
      setState(307);
      dynamic_cast<VarContext *>(_localctx)->exprContext = expr(0);
      setState(308);
      match(MiniCParser::T__15);

              dynamic_cast<VarContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(dynamic_cast<VarContext *>(_localctx)->varnameContext->val);
              _localctx->val->addChild(dynamic_cast<VarContext *>(_localctx)->exprContext->val);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

MiniCParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentsContext::argumentlist() {
  return getRuleContext<MiniCParser::ArgumentlistContext>(0);
}


size_t MiniCParser::ArgumentsContext::getRuleIndex() const {
  return MiniCParser::RuleArguments;
}

void MiniCParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void MiniCParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}

MiniCParser::ArgumentsContext* MiniCParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 32, MiniCParser::RuleArguments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

                _localctx->val.clear();
            
        break;
      }

      case MiniCParser::T__2:
      case MiniCParser::T__20:
      case MiniCParser::T__30:
      case MiniCParser::T__34:
      case MiniCParser::T__35:
      case MiniCParser::ID:
      case MiniCParser::INT:
      case MiniCParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(314);
        dynamic_cast<ArgumentsContext *>(_localctx)->argumentlistContext = argumentlist(0);

                dynamic_cast<ArgumentsContext *>(_localctx)->val =  dynamic_cast<ArgumentsContext *>(_localctx)->argumentlistContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentlistContext ------------------------------------------------------------------

MiniCParser::ArgumentlistContext::ArgumentlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ArgumentlistContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentlistContext::argumentlist() {
  return getRuleContext<MiniCParser::ArgumentlistContext>(0);
}


size_t MiniCParser::ArgumentlistContext::getRuleIndex() const {
  return MiniCParser::RuleArgumentlist;
}

void MiniCParser::ArgumentlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentlist(this);
}

void MiniCParser::ArgumentlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentlist(this);
}


MiniCParser::ArgumentlistContext* MiniCParser::argumentlist() {
   return argumentlist(0);
}

MiniCParser::ArgumentlistContext* MiniCParser::argumentlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ArgumentlistContext *_localctx = _tracker.createInstance<ArgumentlistContext>(_ctx, parentState);
  MiniCParser::ArgumentlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, MiniCParser::RuleArgumentlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(320);
    dynamic_cast<ArgumentlistContext *>(_localctx)->exprContext = expr(0);

            _localctx->val.clear();
            _localctx->val.push_back(dynamic_cast<ArgumentlistContext *>(_localctx)->exprContext->val);
        
    _ctx->stop = _input->LT(-1);
    setState(330);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentlistContext>(parentContext, parentState);
        _localctx->a1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArgumentlist);
        setState(323);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(324);
        match(MiniCParser::T__13);
        setState(325);
        dynamic_cast<ArgumentlistContext *>(_localctx)->exprContext = expr(0);

                          dynamic_cast<ArgumentlistContext *>(_localctx)->val = dynamic_cast<ArgumentlistContext *>(_localctx)->a1->val;
                          _localctx->val.push_back(dynamic_cast<ArgumentlistContext *>(_localctx)->exprContext->val);
                       
      }
      setState(332);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarnameContext ------------------------------------------------------------------

MiniCParser::VarnameContext::VarnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::VarnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::VarnameContext::getRuleIndex() const {
  return MiniCParser::RuleVarname;
}

void MiniCParser::VarnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarname(this);
}

void MiniCParser::VarnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarname(this);
}

MiniCParser::VarnameContext* MiniCParser::varname() {
  VarnameContext *_localctx = _tracker.createInstance<VarnameContext>(_ctx, getState());
  enterRule(_localctx, 36, MiniCParser::RuleVarname);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    dynamic_cast<VarnameContext *>(_localctx)->idToken = match(MiniCParser::ID);

            dynamic_cast<VarnameContext *>(_localctx)->val =  new minicc::Identifier((dynamic_cast<VarnameContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarnameContext *>(_localctx)->idToken->getText() : ""));
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncnameContext ------------------------------------------------------------------

MiniCParser::FuncnameContext::FuncnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::FuncnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::FuncnameContext::getRuleIndex() const {
  return MiniCParser::RuleFuncname;
}

void MiniCParser::FuncnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncname(this);
}

void MiniCParser::FuncnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncname(this);
}

MiniCParser::FuncnameContext* MiniCParser::funcname() {
  FuncnameContext *_localctx = _tracker.createInstance<FuncnameContext>(_ctx, getState());
  enterRule(_localctx, 38, MiniCParser::RuleFuncname);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    dynamic_cast<FuncnameContext *>(_localctx)->idToken = match(MiniCParser::ID);

            dynamic_cast<FuncnameContext *>(_localctx)->val =  new minicc::Identifier((dynamic_cast<FuncnameContext *>(_localctx)->idToken != nullptr ? dynamic_cast<FuncnameContext *>(_localctx)->idToken->getText() : ""));
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameternameContext ------------------------------------------------------------------

MiniCParser::ParameternameContext::ParameternameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ParameternameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::ParameternameContext::getRuleIndex() const {
  return MiniCParser::RuleParametername;
}

void MiniCParser::ParameternameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParametername(this);
}

void MiniCParser::ParameternameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParametername(this);
}

MiniCParser::ParameternameContext* MiniCParser::parametername() {
  ParameternameContext *_localctx = _tracker.createInstance<ParameternameContext>(_ctx, getState());
  enterRule(_localctx, 40, MiniCParser::RuleParametername);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    dynamic_cast<ParameternameContext *>(_localctx)->idToken = match(MiniCParser::ID);

            dynamic_cast<ParameternameContext *>(_localctx)->val =  new minicc::Identifier((dynamic_cast<ParameternameContext *>(_localctx)->idToken != nullptr ? dynamic_cast<ParameternameContext *>(_localctx)->idToken->getText() : ""));
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MiniCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return varlistSempred(dynamic_cast<VarlistContext *>(context), predicateIndex);
    case 11: return parameterlistSempred(dynamic_cast<ParameterlistContext *>(context), predicateIndex);
    case 14: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 17: return argumentlistSempred(dynamic_cast<ArgumentlistContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniCParser::varlistSempred(VarlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::parameterlistSempred(ParameterlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

bool MiniCParser::argumentlistSempred(ArgumentlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MiniCParser::_decisionToDFA;
atn::PredictionContextCache MiniCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MiniCParser::_atn;
std::vector<uint16_t> MiniCParser::_serializedATN;

std::vector<std::string> MiniCParser::_ruleNames = {
  "prog", "preamble", "decl", "vardecl", "scope", "stmt", "varlist", "varlistentry", 
  "vartype", "rettype", "parameters", "parameterlist", "parameterentry", 
  "expropt", "expr", "var", "arguments", "argumentlist", "varname", "funcname", 
  "parametername"
};

std::vector<std::string> MiniCParser::_literalNames = {
  "", "'#include'", "'\"minicio.h\"'", "'('", "')'", "';'", "'{'", "'}'", 
  "'if'", "'else'", "'for'", "'while'", "'break'", "'return'", "','", "'['", 
  "']'", "'int'", "'bool'", "'char'", "'void'", "'-'", "'*'", "'/'", "'+'", 
  "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'!'", "'&&'", "'||'", "'='", 
  "'true'", "'false'"
};

std::vector<std::string> MiniCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "ID", "INT", "CHAR", "WS", "COMMENT"
};

dfa::Vocabulary MiniCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MiniCParser::_tokenNames;

MiniCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0x159, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x5, 0x2, 0x31, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
    0x36, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x39, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x53, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x5e, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x61, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0x66, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x69, 0xb, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xa2, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xad, 0xa, 0x8, 0xc, 0x8, 0xe, 
    0x8, 0xb0, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xbb, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xc3, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0xca, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd0, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xdb, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xde, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xe8, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x111, 
    0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x7, 0x10, 0x12c, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x12f, 0xb, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x13a, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x140, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x7, 0x13, 0x14b, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x14e, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x6, 0xe, 
    0x18, 0x1e, 0x24, 0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2, 0x5, 0x3, 0x2, 0x18, 0x19, 0x4, 0x2, 0x17, 0x17, 0x1a, 0x1a, 0x3, 
    0x2, 0x1b, 0x20, 0x2, 0x16b, 0x2, 0x30, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x52, 0x3, 0x2, 0x2, 0x2, 0x8, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x59, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x10, 0xba, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x16, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x139, 0x3, 0x2, 0x2, 0x2, 0x22, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x141, 0x3, 0x2, 0x2, 0x2, 0x26, 0x14f, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x152, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x155, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2d, 0x5, 0x4, 0x3, 0x2, 0x2d, 0x2e, 0x8, 0x2, 0x1, 0x2, 0x2e, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x31, 0x8, 0x2, 0x1, 0x2, 0x30, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x33, 0x5, 0x6, 0x4, 0x2, 0x33, 0x34, 0x8, 0x2, 0x1, 
    0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x2, 0x2, 0x3, 0x3b, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x3, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x4, 
    0x2, 0x2, 0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x8, 0x5, 
    0x2, 0x40, 0x41, 0x8, 0x4, 0x1, 0x2, 0x41, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x5, 0x14, 0xb, 0x2, 0x43, 0x44, 0x5, 0x28, 0x15, 0x2, 0x44, 
    0x45, 0x7, 0x5, 0x2, 0x2, 0x45, 0x46, 0x5, 0x16, 0xc, 0x2, 0x46, 0x47, 
    0x7, 0x6, 0x2, 0x2, 0x47, 0x48, 0x5, 0xa, 0x6, 0x2, 0x48, 0x49, 0x8, 
    0x4, 0x1, 0x2, 0x49, 0x53, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x14, 
    0xb, 0x2, 0x4b, 0x4c, 0x5, 0x28, 0x15, 0x2, 0x4c, 0x4d, 0x7, 0x5, 0x2, 
    0x2, 0x4d, 0x4e, 0x5, 0x16, 0xc, 0x2, 0x4e, 0x4f, 0x7, 0x6, 0x2, 0x2, 
    0x4f, 0x50, 0x7, 0x7, 0x2, 0x2, 0x50, 0x51, 0x8, 0x4, 0x1, 0x2, 0x51, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x53, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x55, 0x5, 0x12, 0xa, 0x2, 0x55, 0x56, 0x5, 0xe, 
    0x8, 0x2, 0x56, 0x57, 0x7, 0x7, 0x2, 0x2, 0x57, 0x58, 0x8, 0x5, 0x1, 
    0x2, 0x58, 0x9, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5f, 0x7, 0x8, 0x2, 0x2, 
    0x5a, 0x5b, 0x5, 0x8, 0x5, 0x2, 0x5b, 0x5c, 0x8, 0x6, 0x1, 0x2, 0x5c, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x67, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x63, 0x5, 0xc, 0x7, 0x2, 0x63, 0x64, 0x8, 0x6, 0x1, 
    0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x9, 0x2, 0x2, 0x6b, 0x6c, 0x8, 
    0x6, 0x1, 0x2, 0x6c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x1e, 
    0x10, 0x2, 0x6e, 0x6f, 0x7, 0x7, 0x2, 0x2, 0x6f, 0x70, 0x8, 0x7, 0x1, 
    0x2, 0x70, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0xa, 0x2, 0x2, 
    0x72, 0x73, 0x7, 0x5, 0x2, 0x2, 0x73, 0x74, 0x5, 0x1e, 0x10, 0x2, 0x74, 
    0x75, 0x7, 0x6, 0x2, 0x2, 0x75, 0x76, 0x5, 0xc, 0x7, 0x2, 0x76, 0x77, 
    0x8, 0x7, 0x1, 0x2, 0x77, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0xa, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x5, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x1e, 
    0x10, 0x2, 0x7b, 0x7c, 0x7, 0x6, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0xc, 0x7, 
    0x2, 0x7d, 0x7e, 0x7, 0xb, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0xc, 0x7, 0x2, 
    0x7f, 0x80, 0x8, 0x7, 0x1, 0x2, 0x80, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x82, 0x7, 0xc, 0x2, 0x2, 0x82, 0x83, 0x7, 0x5, 0x2, 0x2, 0x83, 0x84, 
    0x5, 0x1c, 0xf, 0x2, 0x84, 0x85, 0x7, 0x7, 0x2, 0x2, 0x85, 0x86, 0x5, 
    0x1c, 0xf, 0x2, 0x86, 0x87, 0x7, 0x7, 0x2, 0x2, 0x87, 0x88, 0x5, 0x1c, 
    0xf, 0x2, 0x88, 0x89, 0x7, 0x6, 0x2, 0x2, 0x89, 0x8a, 0x5, 0xc, 0x7, 
    0x2, 0x8a, 0x8b, 0x8, 0x7, 0x1, 0x2, 0x8b, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8d, 0x7, 0xd, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x5, 0x2, 0x2, 0x8e, 
    0x8f, 0x5, 0x1e, 0x10, 0x2, 0x8f, 0x90, 0x7, 0x6, 0x2, 0x2, 0x90, 0x91, 
    0x5, 0xc, 0x7, 0x2, 0x91, 0x92, 0x8, 0x7, 0x1, 0x2, 0x92, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0xe, 0x2, 0x2, 0x94, 0x95, 0x7, 0x7, 
    0x2, 0x2, 0x95, 0xa2, 0x8, 0x7, 0x1, 0x2, 0x96, 0x97, 0x7, 0xf, 0x2, 
    0x2, 0x97, 0x98, 0x7, 0x7, 0x2, 0x2, 0x98, 0xa2, 0x8, 0x7, 0x1, 0x2, 
    0x99, 0x9a, 0x7, 0xf, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x1e, 0x10, 0x2, 0x9b, 
    0x9c, 0x7, 0x7, 0x2, 0x2, 0x9c, 0x9d, 0x8, 0x7, 0x1, 0x2, 0x9d, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0xa, 0x6, 0x2, 0x9f, 0xa0, 0x8, 
    0x7, 0x1, 0x2, 0xa0, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0x71, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0x81, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0x93, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x96, 0x3, 0x2, 0x2, 0x2, 0xa1, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x8, 0x8, 0x1, 0x2, 0xa4, 0xa5, 0x5, 
    0x10, 0x9, 0x2, 0xa5, 0xa6, 0x8, 0x8, 0x1, 0x2, 0xa6, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xa8, 0xc, 0x3, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x10, 0x2, 
    0x2, 0xa9, 0xaa, 0x5, 0x10, 0x9, 0x2, 0xaa, 0xab, 0x8, 0x8, 0x1, 0x2, 
    0xab, 0xad, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x26, 0x14, 0x2, 0xb2, 0xb3, 0x8, 0x9, 
    0x1, 0x2, 0xb3, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x26, 0x14, 
    0x2, 0xb5, 0xb6, 0x7, 0x11, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x28, 0x2, 0x2, 
    0xb7, 0xb8, 0x7, 0x12, 0x2, 0x2, 0xb8, 0xb9, 0x8, 0x9, 0x1, 0x2, 0xb9, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0x11, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 
    0x13, 0x2, 0x2, 0xbd, 0xc3, 0x8, 0xa, 0x1, 0x2, 0xbe, 0xbf, 0x7, 0x14, 
    0x2, 0x2, 0xbf, 0xc3, 0x8, 0xa, 0x1, 0x2, 0xc0, 0xc1, 0x7, 0x15, 0x2, 
    0x2, 0xc1, 0xc3, 0x8, 0xa, 0x1, 0x2, 0xc2, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x16, 0x2, 0x2, 0xc5, 0xca, 
    0x8, 0xb, 0x1, 0x2, 0xc6, 0xc7, 0x5, 0x12, 0xa, 0x2, 0xc7, 0xc8, 0x8, 
    0xb, 0x1, 0x2, 0xc8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xca, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xd0, 0x8, 0xc, 0x1, 0x2, 0xcc, 0xcd, 0x5, 0x18, 0xd, 0x2, 
    0xcd, 0xce, 0x8, 0xc, 0x1, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x8, 0xd, 0x1, 0x2, 0xd2, 0xd3, 0x5, 
    0x1a, 0xe, 0x2, 0xd3, 0xd4, 0x8, 0xd, 0x1, 0x2, 0xd4, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xd6, 0xc, 0x3, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x10, 0x2, 
    0x2, 0xd7, 0xd8, 0x5, 0x1a, 0xe, 0x2, 0xd8, 0xd9, 0x8, 0xd, 0x1, 0x2, 
    0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xde, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0x19, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x12, 0xa, 0x2, 0xe0, 0xe1, 0x5, 0x2a, 
    0x16, 0x2, 0xe1, 0xe2, 0x8, 0xe, 0x1, 0x2, 0xe2, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe4, 0x5, 0x1e, 0x10, 0x2, 0xe4, 0xe5, 0x8, 0xf, 0x1, 0x2, 
    0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe8, 0x8, 0xf, 0x1, 0x2, 0xe7, 
    0xe3, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x8, 0x10, 0x1, 0x2, 0xea, 0xeb, 0x7, 
    0x28, 0x2, 0x2, 0xeb, 0x111, 0x8, 0x10, 0x1, 0x2, 0xec, 0xed, 0x7, 0x29, 
    0x2, 0x2, 0xed, 0x111, 0x8, 0x10, 0x1, 0x2, 0xee, 0xef, 0x7, 0x17, 0x2, 
    0x2, 0xef, 0xf0, 0x5, 0x1e, 0x10, 0x10, 0xf0, 0xf1, 0x8, 0x10, 0x1, 
    0x2, 0xf1, 0x111, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x21, 0x2, 0x2, 
    0xf3, 0xf4, 0x5, 0x1e, 0x10, 0xc, 0xf4, 0xf5, 0x8, 0x10, 0x1, 0x2, 0xf5, 
    0x111, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x20, 0x11, 0x2, 0xf7, 0xf8, 
    0x7, 0x24, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x1e, 0x10, 0x9, 0xf9, 0xfa, 0x8, 
    0x10, 0x1, 0x2, 0xfa, 0x111, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x25, 
    0x2, 0x2, 0xfc, 0x111, 0x8, 0x10, 0x1, 0x2, 0xfd, 0xfe, 0x7, 0x26, 0x2, 
    0x2, 0xfe, 0x111, 0x8, 0x10, 0x1, 0x2, 0xff, 0x100, 0x7, 0x5, 0x2, 0x2, 
    0x100, 0x101, 0x5, 0x1e, 0x10, 0x2, 0x101, 0x102, 0x7, 0x6, 0x2, 0x2, 
    0x102, 0x103, 0x8, 0x10, 0x1, 0x2, 0x103, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x105, 0x5, 0x20, 0x11, 0x2, 0x105, 0x106, 0x8, 0x10, 0x1, 0x2, 
    0x106, 0x111, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x5, 0x28, 0x15, 0x2, 
    0x108, 0x109, 0x7, 0x5, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x22, 0x12, 0x2, 
    0x10a, 0x10b, 0x7, 0x6, 0x2, 0x2, 0x10b, 0x10c, 0x8, 0x10, 0x1, 0x2, 
    0x10c, 0x111, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x5, 0x2a, 0x16, 0x2, 
    0x10e, 0x10f, 0x8, 0x10, 0x1, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x110, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x110, 0xec, 0x3, 0x2, 0x2, 0x2, 0x110, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0x110, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x110, 0xf6, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x110, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0xff, 0x3, 0x2, 0x2, 0x2, 0x110, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x107, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0xc, 0xf, 
    0x2, 0x2, 0x113, 0x114, 0x9, 0x2, 0x2, 0x2, 0x114, 0x115, 0x5, 0x1e, 
    0x10, 0x10, 0x115, 0x116, 0x8, 0x10, 0x1, 0x2, 0x116, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x118, 0xc, 0xe, 0x2, 0x2, 0x118, 0x119, 0x9, 0x3, 
    0x2, 0x2, 0x119, 0x11a, 0x5, 0x1e, 0x10, 0xf, 0x11a, 0x11b, 0x8, 0x10, 
    0x1, 0x2, 0x11b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0xc, 0xd, 
    0x2, 0x2, 0x11d, 0x11e, 0x9, 0x4, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x1e, 
    0x10, 0xe, 0x11f, 0x120, 0x8, 0x10, 0x1, 0x2, 0x120, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x122, 0xc, 0xb, 0x2, 0x2, 0x122, 0x123, 0x7, 0x22, 
    0x2, 0x2, 0x123, 0x124, 0x5, 0x1e, 0x10, 0xc, 0x124, 0x125, 0x8, 0x10, 
    0x1, 0x2, 0x125, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0xc, 0xa, 
    0x2, 0x2, 0x127, 0x128, 0x7, 0x23, 0x2, 0x2, 0x128, 0x129, 0x5, 0x1e, 
    0x10, 0xb, 0x129, 0x12a, 0x8, 0x10, 0x1, 0x2, 0x12a, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x112, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x12e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x130, 0x131, 0x5, 0x26, 0x14, 0x2, 0x131, 0x132, 0x8, 0x11, 0x1, 
    0x2, 0x132, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x5, 0x26, 0x14, 
    0x2, 0x134, 0x135, 0x7, 0x11, 0x2, 0x2, 0x135, 0x136, 0x5, 0x1e, 0x10, 
    0x2, 0x136, 0x137, 0x7, 0x12, 0x2, 0x2, 0x137, 0x138, 0x8, 0x11, 0x1, 
    0x2, 0x138, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x139, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x139, 0x133, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x140, 0x8, 0x12, 0x1, 0x2, 0x13c, 0x13d, 0x5, 0x24, 0x13, 0x2, 
    0x13d, 0x13e, 0x8, 0x12, 0x1, 0x2, 0x13e, 0x140, 0x3, 0x2, 0x2, 0x2, 
    0x13f, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x140, 0x23, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x8, 0x13, 0x1, 0x2, 
    0x142, 0x143, 0x5, 0x1e, 0x10, 0x2, 0x143, 0x144, 0x8, 0x13, 0x1, 0x2, 
    0x144, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0xc, 0x3, 0x2, 0x2, 
    0x146, 0x147, 0x7, 0x10, 0x2, 0x2, 0x147, 0x148, 0x5, 0x1e, 0x10, 0x2, 
    0x148, 0x149, 0x8, 0x13, 0x1, 0x2, 0x149, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x14a, 0x145, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14f, 
    0x150, 0x7, 0x27, 0x2, 0x2, 0x150, 0x151, 0x8, 0x14, 0x1, 0x2, 0x151, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x7, 0x27, 0x2, 0x2, 0x153, 
    0x154, 0x8, 0x15, 0x1, 0x2, 0x154, 0x29, 0x3, 0x2, 0x2, 0x2, 0x155, 
    0x156, 0x7, 0x27, 0x2, 0x2, 0x156, 0x157, 0x8, 0x16, 0x1, 0x2, 0x157, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x15, 0x30, 0x37, 0x52, 0x5f, 0x67, 0xa1, 
    0xae, 0xba, 0xc2, 0xc9, 0xcf, 0xdc, 0xe7, 0x110, 0x12b, 0x12d, 0x139, 
    0x13f, 0x14c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MiniCParser::Initializer MiniCParser::_init;
