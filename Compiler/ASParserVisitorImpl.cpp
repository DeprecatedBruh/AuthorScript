#include "ASParserVisitorImpl.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Class: SSParserVisitorImpl //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Methods
antlrcpp::Any ASParserVisitorImpl::visitText(ASParser::TextContext *ctx) {
  return visitChildren(ctx);
}