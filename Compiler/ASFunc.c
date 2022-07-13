#include "ASFunc.h"

// std
#include <stdlib.h>

// AS
#include "ASAssert.h"

// Function Actions
typedef enum ASFuncAction {
  // Function Traversal
  CALL = 0,
  RETURNS,
  RETURN,
  // Assignment
  ASSIGN,
} ASFuncAction;

// Author Script Function
typedef struct ASFunc { // vars getter macro needs to be adjusted if pos in struct is changed
  ASObj *vars;
} ASFunc;

#define AS_FUNC_VARS_BUCKET_COUNT 12

// Constructor
ASFunc *asFuncCreate() {
  ASFunc *func = malloc(sizeof(ASFunc) + AS_OBJ_SIZE);
  func->vars = asObjCreateAtMemory(func + AS_OBJ_SIZE, AS_FUNC_VARS_BUCKET_COUNT);
  return func;
}

// Destructor
void asFuncDestroy(ASFunc *const func) {
#ifdef DEBUG
  ASSERT(!func, "No function was passed in.");
#endif
  // Free Object
  asObjDestroy(func->vars);
}