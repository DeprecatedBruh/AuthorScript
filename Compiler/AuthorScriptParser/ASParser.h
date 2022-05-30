
// Generated from /home/deprecated/Documents/Workspace/AuthorScript/Grammar/AuthorScriptParser/ASParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  ASParser : public antlr4::Parser {
public:
  enum {
    OP_EQUALS = 1, OP_PERIOD = 2, OP_DQOUTE = 3, OP_SQOUTE = 4, VALUE_INT = 5, 
    VALUE_FLOAT = 6, VALUE_TRUE = 7, VALUE_FALSE = 8, VALUE_STRING = 9, 
    ID = 10
  };

  enum {
    RuleProgram = 0, RuleVariable = 1
  };

  explicit ASParser(antlr4::TokenStream *input);
  ~ASParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class VariableContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *valueType = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OP_EQUALS();
    antlr4::tree::TerminalNode *VALUE_INT();
    antlr4::tree::TerminalNode *VALUE_FLOAT();
    antlr4::tree::TerminalNode *VALUE_STRING();
    antlr4::tree::TerminalNode *VALUE_TRUE();
    antlr4::tree::TerminalNode *VALUE_FALSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

