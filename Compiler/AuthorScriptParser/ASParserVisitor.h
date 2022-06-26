
// Generated from /home/deprecated/Documents/Workspace/AuthorScript/Grammar/AuthorScriptParser/ASParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "ASParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ASParser.
 */
class  ASParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ASParser.
   */
    virtual antlrcpp::Any visitProgram(ASParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ASParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitPrimAssign(ASParser::PrimAssignContext *context) = 0;

    virtual antlrcpp::Any visitObjectAssign(ASParser::ObjectAssignContext *context) = 0;

    virtual antlrcpp::Any visitFunctionAssign(ASParser::FunctionAssignContext *context) = 0;

    virtual antlrcpp::Any visitVariable(ASParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitFunction(ASParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionParams(ASParser::FunctionParamsContext *context) = 0;

    virtual antlrcpp::Any visitFunctionBody(ASParser::FunctionBodyContext *context) = 0;


};

