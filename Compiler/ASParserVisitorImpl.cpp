#include "ASParserVisitorImpl.hpp"

// std
#include <fstream>
#include <iostream>
#include <vector>

// ANTLR
#include <ASLexer.h>
#include <ASParser.h>
#include <ASParserBaseVisitor.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Class: ASParserVisitorImpl //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
class ASParserVisitorImpl final : public ASParserBaseVisitor {
public:
  // Constructor
  ASParserVisitorImpl(ASObj *const root_obj) : root_obj(root_obj), obj(root_obj) {}
  // Variables
  virtual antlrcpp::Any visitPrimAssign(ASParser::PrimAssignContext *ctx) override;
  virtual antlrcpp::Any visitObjectAssign(ASParser::ObjectAssignContext *ctx) override;
  // Functions
  virtual antlrcpp::Any visitFunction(ASParser::FunctionContext *ctx) override;
  virtual antlrcpp::Any visitFunctionParams(ASParser::FunctionParamsContext *ctx) override;
  virtual antlrcpp::Any visitFunctionBody(ASParser::FunctionBodyContext *ctx) override;
public:
  ASObj *const root_obj;
  ASObj *obj;
};

// Methods
// Variables
antlrcpp::Any ASParserVisitorImpl::visitPrimAssign(ASParser::PrimAssignContext *ctx) {
  std::string var_id = ctx->ID()->toString();
  ASVar var = { NULL, (const aschar *)asObjAddString(obj, var_id.c_str()), AS_TYPE_NIL };
  // Determine Type And Set Value
  switch(ctx->valueType->getType()) {
    case(size_t)ASParser::VALUE_INT: {
      var.type = AS_TYPE_INTEGER;
      const int64_t value = atoll(ctx->VALUE_INT()->toString().c_str());
      var.data.value_i = (int64_t *)asObjAddData(obj, &value, sizeof(value));
    } break;
    case(size_t)ASParser::VALUE_FLOAT: {
      var.type = AS_TYPE_FLOAT;
      const double value = atof(ctx->VALUE_FLOAT()->toString().c_str());
      var.data.value_f = (double *)asObjAddData(obj, &value, sizeof(value));
    } break;
    case(size_t)ASParser::VALUE_STRING: {
      var.type = AS_TYPE_STRING;
      std::string value = ctx->VALUE_STRING()->toString();
      value.at(value.length() - 1) = '\0';                     // Ends string before last '"'
      var.data.str = (aschar *)asObjAddString(obj, &value[1]); // Starts string after first '"'
    } break;
    case(size_t)ASParser::VALUE_TRUE: {
      var.type = AS_TYPE_BOOLEAN;
      const asbool value = true;
      var.data.value_b = (asbool *)asObjAddData(obj, &value, sizeof(value));
    } break;
    case(size_t)ASParser::VALUE_FALSE: {
      var.type = AS_TYPE_BOOLEAN;
      const asbool value = false;
      var.data.value_b = (asbool *)asObjAddData(obj, &value, sizeof(value));
    } break;
  }
  // Add Variable
  return asObjSetVar(obj, var);
}

#define AS_OBJ_CHILD_BUCKETS 12
antlrcpp::Any ASParserVisitorImpl::visitObjectAssign(ASParser::ObjectAssignContext *ctx) {
  // Create new child object
  ASObj *const parent_obj = this->obj;
  ASObj *const child_obj = this->obj = asObjCreate(AS_OBJ_CHILD_BUCKETS);
  ASVar var = { child_obj, (const aschar *)asObjAddString(parent_obj, ctx->ID()->toString().c_str()), AS_TYPE_OBJECT };
  asObjSetVar(parent_obj, var);
  // Loop through and process variables
  for(auto &var_ctx : ctx->var()) visit(var_ctx);
  // Reset obj to parent
  this->obj = parent_obj;
  return child_obj;
}
#undef AS_OBJ_CHILD_BUCKETS

// Functions
#define AS_FUNC_OBJ_CHILD_BUCKETS 16
antlrcpp::Any ASParserVisitorImpl::visitFunction(ASParser::FunctionContext *ctx) {
  // Create Function Body
  ASObj *const parent_obj = this->obj;
  ASObj *const func_body = this->obj = asObjCreate(AS_FUNC_OBJ_CHILD_BUCKETS);
  ASVar var = { func_body, (const aschar *)asObjAddString(parent_obj, ctx->ID()->toString().c_str()), AS_TYPE_OBJECT };
  asObjSetVar(parent_obj, var);
  // Process Function Parameters
  if(ctx->functionParams())
    visitFunctionParams(ctx->functionParams());
  // Process Function Body
  if(ctx->functionBody())
    visitFunctionBody(ctx->functionBody());
  // Reset obj to parent
  this->obj = parent_obj;
  return func_body;
}
#undef AS_FUNC_OBJ_CHILD_BUCKETS

antlrcpp::Any ASParserVisitorImpl::visitFunctionParams(ASParser::FunctionParamsContext *ctx) {
  std::vector<ASVar> params;
  // Get Variables
  for(auto &id : ctx->ID()) {
    // aschar *name = asObjAddString(obj, id->toString().c_str());
    // TODO: Finish this! Need a way to reference other data.
  }
  return visitChildren(ctx);
}

antlrcpp::Any ASParserVisitorImpl::visitFunctionBody(ASParser::FunctionBodyContext *ctx) {
  // TODO: Work on function body!
  return visitChildren(ctx);
}

// Parser Starter
EXTERN_C void asRunParser(ASObj *root_obj, const char *file_path) {
  std::ifstream in_file(file_path);
  if(in_file) {
    antlr4::ANTLRInputStream in(in_file);
    ASLexer lexer(&in);
    antlr4::CommonTokenStream tokens(&lexer);
    ASParser parser(&tokens);

    ASParserVisitorImpl visitor(root_obj);
    visitor.visitProgram(parser.program());
  }
  else {
    std::cerr << "File was invalid: \"" << file_path << "\"\n";
  }
}