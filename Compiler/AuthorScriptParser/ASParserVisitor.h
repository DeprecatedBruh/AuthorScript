
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

    virtual antlrcpp::Any visitVariable(ASParser::VariableContext *context) = 0;


};

