#ifndef _AUTHOR_SCRIPT_PARSER_IMPL_H_
#define _AUTHOR_SCRIPT_PARSER_IMPL_H_

#include <ASParserBaseVisitor.h>

class ASParserVisitorImpl final : public ASParserBaseVisitor {
public:
  virtual antlrcpp::Any visitVariable(ASParser::VariableContext *ctx) override;
};

#endif