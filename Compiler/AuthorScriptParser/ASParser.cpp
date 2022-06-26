
// Generated from /home/deprecated/Documents/Workspace/AuthorScript/Grammar/AuthorScriptParser/ASParser.g4 by ANTLR 4.9.3


#include "ASParserVisitor.h"

#include "ASParser.h"


using namespace antlrcpp;
using namespace antlr4;

ASParser::ASParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ASParser::~ASParser() {
  delete _interpreter;
}

std::string ASParser::getGrammarFileName() const {
  return "ASParser.g4";
}

const std::vector<std::string>& ASParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ASParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

ASParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ASParser::StatementContext *> ASParser::ProgramContext::statement() {
  return getRuleContexts<ASParser::StatementContext>();
}

ASParser::StatementContext* ASParser::ProgramContext::statement(size_t i) {
  return getRuleContext<ASParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> ASParser::ProgramContext::NL() {
  return getTokens(ASParser::NL);
}

tree::TerminalNode* ASParser::ProgramContext::NL(size_t i) {
  return getToken(ASParser::NL, i);
}


size_t ASParser::ProgramContext::getRuleIndex() const {
  return ASParser::RuleProgram;
}


antlrcpp::Any ASParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ASParser::ProgramContext* ASParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ASParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ASParser::ID)
      | (1ULL << ASParser::FUNCTION)
      | (1ULL << ASParser::NL))) != 0)) {
      setState(12);
      statement();
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ASParser::NL) {
        setState(13);
        match(ASParser::NL);
        setState(14);
        statement();
        setState(19);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- StatementContext ------------------------------------------------------------------

ASParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASParser::VarContext* ASParser::StatementContext::var() {
  return getRuleContext<ASParser::VarContext>(0);
}

ASParser::FunctionContext* ASParser::StatementContext::function() {
  return getRuleContext<ASParser::FunctionContext>(0);
}

tree::TerminalNode* ASParser::StatementContext::NL() {
  return getToken(ASParser::NL, 0);
}


size_t ASParser::StatementContext::getRuleIndex() const {
  return ASParser::RuleStatement;
}


antlrcpp::Any ASParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ASParser::StatementContext* ASParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, ASParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(25);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(22);
        var();
        break;
      }

      case ASParser::FUNCTION: {
        enterOuterAlt(_localctx, 2);
        setState(23);
        function();
        break;
      }

      case ASParser::NL: {
        enterOuterAlt(_localctx, 3);
        setState(24);
        match(ASParser::NL);
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

//----------------- VarContext ------------------------------------------------------------------

ASParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ASParser::VarContext::getRuleIndex() const {
  return ASParser::RuleVar;
}

void ASParser::VarContext::copyFrom(VarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionAssignContext ------------------------------------------------------------------

tree::TerminalNode* ASParser::FunctionAssignContext::ID() {
  return getToken(ASParser::ID, 0);
}

tree::TerminalNode* ASParser::FunctionAssignContext::EQUALS() {
  return getToken(ASParser::EQUALS, 0);
}

tree::TerminalNode* ASParser::FunctionAssignContext::FUNCTION() {
  return getToken(ASParser::FUNCTION, 0);
}

ASParser::FunctionParamsContext* ASParser::FunctionAssignContext::functionParams() {
  return getRuleContext<ASParser::FunctionParamsContext>(0);
}

tree::TerminalNode* ASParser::FunctionAssignContext::DO() {
  return getToken(ASParser::DO, 0);
}

std::vector<tree::TerminalNode *> ASParser::FunctionAssignContext::NL() {
  return getTokens(ASParser::NL);
}

tree::TerminalNode* ASParser::FunctionAssignContext::NL(size_t i) {
  return getToken(ASParser::NL, i);
}

tree::TerminalNode* ASParser::FunctionAssignContext::END() {
  return getToken(ASParser::END, 0);
}

ASParser::FunctionBodyContext* ASParser::FunctionAssignContext::functionBody() {
  return getRuleContext<ASParser::FunctionBodyContext>(0);
}

ASParser::FunctionAssignContext::FunctionAssignContext(VarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ASParser::FunctionAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitFunctionAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjectAssignContext ------------------------------------------------------------------

tree::TerminalNode* ASParser::ObjectAssignContext::ID() {
  return getToken(ASParser::ID, 0);
}

tree::TerminalNode* ASParser::ObjectAssignContext::EQUALS() {
  return getToken(ASParser::EQUALS, 0);
}

tree::TerminalNode* ASParser::ObjectAssignContext::LBRACE() {
  return getToken(ASParser::LBRACE, 0);
}

std::vector<tree::TerminalNode *> ASParser::ObjectAssignContext::NL() {
  return getTokens(ASParser::NL);
}

tree::TerminalNode* ASParser::ObjectAssignContext::NL(size_t i) {
  return getToken(ASParser::NL, i);
}

tree::TerminalNode* ASParser::ObjectAssignContext::RBRACE() {
  return getToken(ASParser::RBRACE, 0);
}

std::vector<ASParser::VarContext *> ASParser::ObjectAssignContext::var() {
  return getRuleContexts<ASParser::VarContext>();
}

ASParser::VarContext* ASParser::ObjectAssignContext::var(size_t i) {
  return getRuleContext<ASParser::VarContext>(i);
}

ASParser::ObjectAssignContext::ObjectAssignContext(VarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ASParser::ObjectAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitObjectAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrimAssignContext ------------------------------------------------------------------

tree::TerminalNode* ASParser::PrimAssignContext::ID() {
  return getToken(ASParser::ID, 0);
}

tree::TerminalNode* ASParser::PrimAssignContext::EQUALS() {
  return getToken(ASParser::EQUALS, 0);
}

tree::TerminalNode* ASParser::PrimAssignContext::VALUE_INT() {
  return getToken(ASParser::VALUE_INT, 0);
}

tree::TerminalNode* ASParser::PrimAssignContext::VALUE_FLOAT() {
  return getToken(ASParser::VALUE_FLOAT, 0);
}

tree::TerminalNode* ASParser::PrimAssignContext::VALUE_STRING() {
  return getToken(ASParser::VALUE_STRING, 0);
}

tree::TerminalNode* ASParser::PrimAssignContext::VALUE_TRUE() {
  return getToken(ASParser::VALUE_TRUE, 0);
}

tree::TerminalNode* ASParser::PrimAssignContext::VALUE_FALSE() {
  return getToken(ASParser::VALUE_FALSE, 0);
}

ASParser::PrimAssignContext::PrimAssignContext(VarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ASParser::PrimAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitPrimAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* ASParser::VariableContext::ID() {
  return getToken(ASParser::ID, 0);
}

ASParser::VariableContext::VariableContext(VarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ASParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
ASParser::VarContext* ASParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 4, ASParser::RuleVar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ASParser::PrimAssignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(27);
      match(ASParser::ID);
      setState(28);
      match(ASParser::EQUALS);
      setState(29);
      antlrcpp::downCast<PrimAssignContext *>(_localctx)->valueType = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ASParser::VALUE_INT)
        | (1ULL << ASParser::VALUE_FLOAT)
        | (1ULL << ASParser::VALUE_TRUE)
        | (1ULL << ASParser::VALUE_FALSE)
        | (1ULL << ASParser::VALUE_STRING))) != 0))) {
        antlrcpp::downCast<PrimAssignContext *>(_localctx)->valueType = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ASParser::ObjectAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(30);
      match(ASParser::ID);
      setState(31);
      match(ASParser::EQUALS);
      setState(32);
      match(ASParser::LBRACE);
      setState(33);
      match(ASParser::NL);
      setState(39);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ASParser::ID) {
        setState(34);
        var();
        setState(35);
        match(ASParser::NL);
        setState(41);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(42);
      match(ASParser::RBRACE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ASParser::FunctionAssignContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(43);
      match(ASParser::ID);
      setState(44);
      match(ASParser::EQUALS);
      setState(45);
      match(ASParser::FUNCTION);
      setState(46);
      functionParams();
      setState(47);
      match(ASParser::DO);
      setState(48);
      match(ASParser::NL);
      setState(50);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(49);
        functionBody(0);
        break;
      }

      default:
        break;
      }
      setState(52);
      match(ASParser::NL);
      setState(53);
      match(ASParser::END);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ASParser::VariableContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(55);
      match(ASParser::ID);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

ASParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASParser::FunctionContext::FUNCTION() {
  return getToken(ASParser::FUNCTION, 0);
}

tree::TerminalNode* ASParser::FunctionContext::ID() {
  return getToken(ASParser::ID, 0);
}

ASParser::FunctionParamsContext* ASParser::FunctionContext::functionParams() {
  return getRuleContext<ASParser::FunctionParamsContext>(0);
}

tree::TerminalNode* ASParser::FunctionContext::DO() {
  return getToken(ASParser::DO, 0);
}

std::vector<tree::TerminalNode *> ASParser::FunctionContext::NL() {
  return getTokens(ASParser::NL);
}

tree::TerminalNode* ASParser::FunctionContext::NL(size_t i) {
  return getToken(ASParser::NL, i);
}

tree::TerminalNode* ASParser::FunctionContext::END() {
  return getToken(ASParser::END, 0);
}

ASParser::FunctionBodyContext* ASParser::FunctionContext::functionBody() {
  return getRuleContext<ASParser::FunctionBodyContext>(0);
}


size_t ASParser::FunctionContext::getRuleIndex() const {
  return ASParser::RuleFunction;
}


antlrcpp::Any ASParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

ASParser::FunctionContext* ASParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 6, ASParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(ASParser::FUNCTION);
    setState(59);
    match(ASParser::ID);
    setState(60);
    functionParams();
    setState(61);
    match(ASParser::DO);
    setState(62);
    match(ASParser::NL);
    setState(64);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(63);
      functionBody(0);
      break;
    }

    default:
      break;
    }
    setState(66);
    match(ASParser::NL);
    setState(67);
    match(ASParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParamsContext ------------------------------------------------------------------

ASParser::FunctionParamsContext::FunctionParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASParser::FunctionParamsContext::LPAREN() {
  return getToken(ASParser::LPAREN, 0);
}

tree::TerminalNode* ASParser::FunctionParamsContext::RPAREN() {
  return getToken(ASParser::RPAREN, 0);
}

std::vector<ASParser::VarContext *> ASParser::FunctionParamsContext::var() {
  return getRuleContexts<ASParser::VarContext>();
}

ASParser::VarContext* ASParser::FunctionParamsContext::var(size_t i) {
  return getRuleContext<ASParser::VarContext>(i);
}

std::vector<tree::TerminalNode *> ASParser::FunctionParamsContext::COMMA() {
  return getTokens(ASParser::COMMA);
}

tree::TerminalNode* ASParser::FunctionParamsContext::COMMA(size_t i) {
  return getToken(ASParser::COMMA, i);
}


size_t ASParser::FunctionParamsContext::getRuleIndex() const {
  return ASParser::RuleFunctionParams;
}


antlrcpp::Any ASParser::FunctionParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitFunctionParams(this);
  else
    return visitor->visitChildren(this);
}

ASParser::FunctionParamsContext* ASParser::functionParams() {
  FunctionParamsContext *_localctx = _tracker.createInstance<FunctionParamsContext>(_ctx, getState());
  enterRule(_localctx, 8, ASParser::RuleFunctionParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(ASParser::LPAREN);
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ASParser::ID) {
      setState(70);
      var();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ASParser::COMMA) {
        setState(71);
        match(ASParser::COMMA);
        setState(72);
        var();
        setState(77);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(80);
    match(ASParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

ASParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASParser::StatementContext* ASParser::FunctionBodyContext::statement() {
  return getRuleContext<ASParser::StatementContext>(0);
}

std::vector<ASParser::FunctionBodyContext *> ASParser::FunctionBodyContext::functionBody() {
  return getRuleContexts<ASParser::FunctionBodyContext>();
}

ASParser::FunctionBodyContext* ASParser::FunctionBodyContext::functionBody(size_t i) {
  return getRuleContext<ASParser::FunctionBodyContext>(i);
}

std::vector<tree::TerminalNode *> ASParser::FunctionBodyContext::NL() {
  return getTokens(ASParser::NL);
}

tree::TerminalNode* ASParser::FunctionBodyContext::NL(size_t i) {
  return getToken(ASParser::NL, i);
}


size_t ASParser::FunctionBodyContext::getRuleIndex() const {
  return ASParser::RuleFunctionBody;
}


antlrcpp::Any ASParser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitFunctionBody(this);
  else
    return visitor->visitChildren(this);
}


ASParser::FunctionBodyContext* ASParser::functionBody() {
   return functionBody(0);
}

ASParser::FunctionBodyContext* ASParser::functionBody(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ASParser::FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, parentState);
  ASParser::FunctionBodyContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, ASParser::RuleFunctionBody, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(83);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(94);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<FunctionBodyContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleFunctionBody);
        setState(85);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(88); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(86);
                  match(ASParser::NL);
                  setState(87);
                  functionBody(0);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(90); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER); 
      }
      setState(96);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ASParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return functionBodySempred(antlrcpp::downCast<FunctionBodyContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ASParser::functionBodySempred(FunctionBodyContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ASParser::_decisionToDFA;
atn::PredictionContextCache ASParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ASParser::_atn;
std::vector<uint16_t> ASParser::_serializedATN;

std::vector<std::string> ASParser::_ruleNames = {
  "program", "statement", "var", "function", "functionParams", "functionBody"
};

std::vector<std::string> ASParser::_literalNames = {
  "", "'\"'", "'''", "'{'", "'}'", "'='", "'.'", "", "", "'true'", "'false'", 
  "", "", "'function'", "'('", "')'", "','", "'do'", "'end'"
};

std::vector<std::string> ASParser::_symbolicNames = {
  "", "DQOUTE", "SQOUTE", "LBRACE", "RBRACE", "EQUALS", "PERIOD", "VALUE_INT", 
  "VALUE_FLOAT", "VALUE_TRUE", "VALUE_FALSE", "VALUE_STRING", "ID", "FUNCTION", 
  "LPAREN", "RPAREN", "COMMA", "DO", "END", "IGNORE_NL", "NL", "WS"
};

dfa::Vocabulary ASParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ASParser::_tokenNames;

ASParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x17, 0x64, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x12, 0xa, 0x2, 0xc, 
       0x2, 0xe, 0x2, 0x15, 0xb, 0x2, 0x5, 0x2, 0x17, 0xa, 0x2, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x7, 0x4, 0x28, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x2b, 
       0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3b, 0xa, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x43, 0xa, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x7, 0x6, 0x4c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4f, 0xb, 
       0x6, 0x5, 0x6, 0x51, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x5b, 0xa, 
       0x7, 0xd, 0x7, 0xe, 0x7, 0x5c, 0x7, 0x7, 0x5f, 0xa, 0x7, 0xc, 0x7, 
       0xe, 0x7, 0x62, 0xb, 0x7, 0x3, 0x7, 0x2, 0x3, 0xc, 0x8, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0xc, 0x2, 0x3, 0x3, 0x2, 0x9, 0xd, 0x2, 0x6b, 0x2, 
       0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3a, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x47, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x54, 0x3, 0x2, 0x2, 0x2, 0xe, 0x13, 0x5, 0x4, 
       0x3, 0x2, 0xf, 0x10, 0x7, 0x16, 0x2, 0x2, 0x10, 0x12, 0x5, 0x4, 0x3, 
       0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x12, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 0x2, 0x2, 0x2, 0x14, 
       0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 0x16, 0xe, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 0x2, 0x2, 0x2, 0x17, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x18, 0x1c, 0x5, 0x6, 0x4, 0x2, 0x19, 0x1c, 0x5, 0x8, 
       0x5, 0x2, 0x1a, 0x1c, 0x7, 0x16, 0x2, 0x2, 0x1b, 0x18, 0x3, 0x2, 
       0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0xe, 0x2, 0x2, 
       0x1e, 0x1f, 0x7, 0x7, 0x2, 0x2, 0x1f, 0x3b, 0x9, 0x2, 0x2, 0x2, 0x20, 
       0x21, 0x7, 0xe, 0x2, 0x2, 0x21, 0x22, 0x7, 0x7, 0x2, 0x2, 0x22, 0x23, 
       0x7, 0x5, 0x2, 0x2, 0x23, 0x29, 0x7, 0x16, 0x2, 0x2, 0x24, 0x25, 
       0x5, 0x6, 0x4, 0x2, 0x25, 0x26, 0x7, 0x16, 0x2, 0x2, 0x26, 0x28, 
       0x3, 0x2, 0x2, 0x2, 0x27, 0x24, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x3, 
       0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 
       0x2, 0x2c, 0x3b, 0x7, 0x6, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0xe, 0x2, 0x2, 
       0x2e, 0x2f, 0x7, 0x7, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xf, 0x2, 0x2, 0x30, 
       0x31, 0x5, 0xa, 0x6, 0x2, 0x31, 0x32, 0x7, 0x13, 0x2, 0x2, 0x32, 
       0x34, 0x7, 0x16, 0x2, 0x2, 0x33, 0x35, 0x5, 0xc, 0x7, 0x2, 0x34, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
       0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x16, 0x2, 0x2, 0x37, 0x38, 
       0x7, 0x14, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3b, 
       0x7, 0xe, 0x2, 0x2, 0x3a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x20, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0xf, 0x2, 
       0x2, 0x3d, 0x3e, 0x7, 0xe, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0xa, 0x6, 0x2, 
       0x3f, 0x40, 0x7, 0x13, 0x2, 0x2, 0x40, 0x42, 0x7, 0x16, 0x2, 0x2, 
       0x41, 0x43, 0x5, 0xc, 0x7, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x42, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 
       0x7, 0x16, 0x2, 0x2, 0x45, 0x46, 0x7, 0x14, 0x2, 0x2, 0x46, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0x47, 0x50, 0x7, 0x10, 0x2, 0x2, 0x48, 0x4d, 
       0x5, 0x6, 0x4, 0x2, 0x49, 0x4a, 0x7, 0x12, 0x2, 0x2, 0x4a, 0x4c, 
       0x5, 0x6, 0x4, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x3, 
       0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 
       0x2, 0x50, 0x48, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 
       0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x11, 0x2, 0x2, 
       0x53, 0xb, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x8, 0x7, 0x1, 0x2, 0x55, 
       0x56, 0x5, 0x4, 0x3, 0x2, 0x56, 0x60, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 
       0xc, 0x4, 0x2, 0x2, 0x58, 0x59, 0x7, 0x16, 0x2, 0x2, 0x59, 0x5b, 
       0x5, 0xc, 0x7, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 
       0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 
       0x2, 0x2, 0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x57, 0x3, 0x2, 0x2, 
       0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 
       0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0xd, 0x3, 0x2, 0x2, 0x2, 0x62, 
       0x60, 0x3, 0x2, 0x2, 0x2, 0xd, 0x13, 0x16, 0x1b, 0x29, 0x34, 0x3a, 
       0x42, 0x4d, 0x50, 0x5c, 0x60, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ASParser::Initializer ASParser::_init;
