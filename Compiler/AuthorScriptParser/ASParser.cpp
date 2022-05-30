
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

std::vector<ASParser::VariableContext *> ASParser::ProgramContext::variable() {
  return getRuleContexts<ASParser::VariableContext>();
}

ASParser::VariableContext* ASParser::ProgramContext::variable(size_t i) {
  return getRuleContext<ASParser::VariableContext>(i);
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
    setState(7);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ASParser::ID) {
      setState(4);
      variable();
      setState(9);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

ASParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASParser::VariableContext::ID() {
  return getToken(ASParser::ID, 0);
}

tree::TerminalNode* ASParser::VariableContext::OP_EQUALS() {
  return getToken(ASParser::OP_EQUALS, 0);
}

tree::TerminalNode* ASParser::VariableContext::VALUE_INT() {
  return getToken(ASParser::VALUE_INT, 0);
}

tree::TerminalNode* ASParser::VariableContext::VALUE_FLOAT() {
  return getToken(ASParser::VALUE_FLOAT, 0);
}

tree::TerminalNode* ASParser::VariableContext::VALUE_STRING() {
  return getToken(ASParser::VALUE_STRING, 0);
}

tree::TerminalNode* ASParser::VariableContext::VALUE_TRUE() {
  return getToken(ASParser::VALUE_TRUE, 0);
}

tree::TerminalNode* ASParser::VariableContext::VALUE_FALSE() {
  return getToken(ASParser::VALUE_FALSE, 0);
}


size_t ASParser::VariableContext::getRuleIndex() const {
  return ASParser::RuleVariable;
}


antlrcpp::Any ASParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

ASParser::VariableContext* ASParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 2, ASParser::RuleVariable);
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
    setState(10);
    match(ASParser::ID);
    setState(11);
    match(ASParser::OP_EQUALS);
    setState(12);
    antlrcpp::downCast<VariableContext *>(_localctx)->valueType = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ASParser::VALUE_INT)
      | (1ULL << ASParser::VALUE_FLOAT)
      | (1ULL << ASParser::VALUE_TRUE)
      | (1ULL << ASParser::VALUE_FALSE)
      | (1ULL << ASParser::VALUE_STRING))) != 0))) {
      antlrcpp::downCast<VariableContext *>(_localctx)->valueType = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ASParser::_decisionToDFA;
atn::PredictionContextCache ASParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ASParser::_atn;
std::vector<uint16_t> ASParser::_serializedATN;

std::vector<std::string> ASParser::_ruleNames = {
  "program", "variable"
};

std::vector<std::string> ASParser::_literalNames = {
  "", "'='", "'.'", "'\"'", "'''", "", "", "'true'", "'false'"
};

std::vector<std::string> ASParser::_symbolicNames = {
  "", "OP_EQUALS", "OP_PERIOD", "OP_DQOUTE", "OP_SQOUTE", "VALUE_INT", "VALUE_FLOAT", 
  "VALUE_TRUE", "VALUE_FALSE", "VALUE_STRING", "ID"
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
       0x3, 0xc, 0x11, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 
       0x7, 0x2, 0x8, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xb, 0xb, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x4, 0x2, 
       0x4, 0x2, 0x3, 0x3, 0x2, 0x7, 0xb, 0x2, 0xf, 0x2, 0x9, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0xc, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8, 0x5, 0x4, 0x3, 
       0x2, 0x7, 0x6, 0x3, 0x2, 0x2, 0x2, 0x8, 0xb, 0x3, 0x2, 0x2, 0x2, 
       0x9, 0x7, 0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x3, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 
       0x7, 0xc, 0x2, 0x2, 0xd, 0xe, 0x7, 0x3, 0x2, 0x2, 0xe, 0xf, 0x9, 
       0x2, 0x2, 0x2, 0xf, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3, 0x9, 
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
