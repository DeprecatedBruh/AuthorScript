
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


//----------------- TextContext ------------------------------------------------------------------

ASParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ASParser::TextContext::TEXT() {
  return getTokens(ASParser::TEXT);
}

tree::TerminalNode* ASParser::TextContext::TEXT(size_t i) {
  return getToken(ASParser::TEXT, i);
}


size_t ASParser::TextContext::getRuleIndex() const {
  return ASParser::RuleText;
}


antlrcpp::Any ASParser::TextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ASParserVisitor*>(visitor))
    return parserVisitor->visitText(this);
  else
    return visitor->visitChildren(this);
}

ASParser::TextContext* ASParser::text() {
  TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, getState());
  enterRule(_localctx, 0, ASParser::RuleText);
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
    setState(5);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ASParser::TEXT) {
      setState(2);
      match(ASParser::TEXT);
      setState(7);
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

// Static vars and initialization.
std::vector<dfa::DFA> ASParser::_decisionToDFA;
atn::PredictionContextCache ASParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ASParser::_atn;
std::vector<uint16_t> ASParser::_serializedATN;

std::vector<std::string> ASParser::_ruleNames = {
  "text"
};

std::vector<std::string> ASParser::_literalNames = {
};

std::vector<std::string> ASParser::_symbolicNames = {
  "", "TEXT"
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
       0x3, 0x3, 0xb, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x7, 0x2, 0x6, 0xa, 
       0x2, 0xc, 0x2, 0xe, 0x2, 0x9, 0xb, 0x2, 0x3, 0x2, 0x2, 0x2, 0x3, 
       0x2, 0x2, 0x2, 0x2, 0xa, 0x2, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4, 0x6, 
       0x7, 0x3, 0x2, 0x2, 0x5, 0x4, 0x3, 0x2, 0x2, 0x2, 0x6, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x7, 0x5, 0x3, 0x2, 0x2, 0x2, 0x7, 0x8, 0x3, 0x2, 
       0x2, 0x2, 0x8, 0x3, 0x3, 0x2, 0x2, 0x2, 0x9, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x3, 0x7, 
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
