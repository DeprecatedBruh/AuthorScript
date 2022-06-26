
// Generated from /home/deprecated/Documents/Workspace/AuthorScript/Grammar/AuthorScriptParser/ASLexer.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  ASLexer : public antlr4::Lexer {
public:
  enum {
    DQOUTE = 1, SQOUTE = 2, LBRACE = 3, RBRACE = 4, EQUALS = 5, PERIOD = 6, 
    VALUE_INT = 7, VALUE_FLOAT = 8, VALUE_TRUE = 9, VALUE_FALSE = 10, VALUE_STRING = 11, 
    ID = 12, FUNCTION = 13, LPAREN = 14, RPAREN = 15, COMMA = 16, DO = 17, 
    END = 18, IGNORE_NL = 19, NL = 20, WS = 21
  };

  explicit ASLexer(antlr4::CharStream *input);
  ~ASLexer();

   
    bool ignoreNewlines() const {
      return paren_nesting > 0;
    }
    // Members
    unsigned long long int paren_nesting = 0;

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void LPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARENAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool IGNORE_NLSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

