#include "ASParserVisitorImpl.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Class: ASParserVisitorImpl //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Methods
antlrcpp::Any ASParserVisitorImpl::visitVariable(ASParser::VariableContext *ctx) {
  return visitChildren(ctx);
}