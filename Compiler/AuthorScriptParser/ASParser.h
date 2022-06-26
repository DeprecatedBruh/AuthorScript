
// Generated from /home/deprecated/Documents/Workspace/AuthorScript/Grammar/AuthorScriptParser/ASParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  ASParser : public antlr4::Parser {
public:
  enum {
    DQOUTE = 1, SQOUTE = 2, LBRACE = 3, RBRACE = 4, EQUALS = 5, PERIOD = 6, 
    VALUE_INT = 7, VALUE_FLOAT = 8, VALUE_TRUE = 9, VALUE_FALSE = 10, VALUE_STRING = 11, 
    ID = 12, FUNCTION = 13, LPAREN = 14, RPAREN = 15, COMMA = 16, DO = 17, 
    END = 18, IGNORE_NL = 19, NL = 20, WS = 21
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleVar = 2, RuleFunction = 3, RuleFunctionParams = 4, 
    RuleFunctionBody = 5
  };

  explicit ASParser(antlr4::TokenStream *input);
  ~ASParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class StatementContext;
  class VarContext;
  class FunctionContext;
  class FunctionParamsContext;
  class FunctionBodyContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    FunctionContext *function();
    antlr4::tree::TerminalNode *NL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarContext() = default;
    void copyFrom(VarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionAssignContext : public VarContext {
  public:
    FunctionAssignContext(VarContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *FUNCTION();
    FunctionParamsContext *functionParams();
    antlr4::tree::TerminalNode *DO();
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);
    antlr4::tree::TerminalNode *END();
    FunctionBodyContext *functionBody();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ObjectAssignContext : public VarContext {
  public:
    ObjectAssignContext(VarContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<VarContext *> var();
    VarContext* var(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimAssignContext : public VarContext {
  public:
    PrimAssignContext(VarContext *ctx);

    antlr4::Token *valueType = nullptr;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *VALUE_INT();
    antlr4::tree::TerminalNode *VALUE_FLOAT();
    antlr4::tree::TerminalNode *VALUE_STRING();
    antlr4::tree::TerminalNode *VALUE_TRUE();
    antlr4::tree::TerminalNode *VALUE_FALSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableContext : public VarContext {
  public:
    VariableContext(VarContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarContext* var();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    antlr4::tree::TerminalNode *ID();
    FunctionParamsContext *functionParams();
    antlr4::tree::TerminalNode *DO();
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);
    antlr4::tree::TerminalNode *END();
    FunctionBodyContext *functionBody();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  FunctionParamsContext : public antlr4::ParserRuleContext {
  public:
    FunctionParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<VarContext *> var();
    VarContext* var(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionParamsContext* functionParams();

  class  FunctionBodyContext : public antlr4::ParserRuleContext {
  public:
    FunctionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    std::vector<FunctionBodyContext *> functionBody();
    FunctionBodyContext* functionBody(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionBodyContext* functionBody();
  FunctionBodyContext* functionBody(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool functionBodySempred(FunctionBodyContext *_localctx, size_t predicateIndex);

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

