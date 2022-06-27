
// Generated from /home/deprecated/Documents/Workspace/AuthorScript/Grammar/AuthorScriptParser/ASParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "ASParserVisitor.h"


/**
 * This class provides an empty implementation of ASParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ASParserBaseVisitor : public ASParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(ASParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(ASParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimAssign(ASParser::PrimAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectAssign(ASParser::ObjectAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ASParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(ASParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionParams(ASParser::FunctionParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionBody(ASParser::FunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }


};

