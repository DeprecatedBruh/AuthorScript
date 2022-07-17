#include "ASFunc.h"

// std
#include <stdlib.h>

// AS
#include "ASAssert.h"

// Author Script Function
typedef struct ASFunc {
  ASObj *vars;
  char *func_body;
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