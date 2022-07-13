#ifndef _ASDATA_H_
#define _ASDATA_H_

// std
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// AS
#include "ASFunc.h" // Both 'ASData.h' and 'ASFunc.h' should always be included together

#ifdef __cplusplus
// C++ Stuff
#define _Bool bool

extern "C" { // wraps C code for the sake of C++ includes
#else
// C Stuff
#endif

// Author Script Object Forward Declaration
struct ASObj;
typedef struct ASObj ASObj;
extern const size_t AS_OBJ_SIZE;

// Custom Types
typedef char aschar;     // Makes it slightly easier to switch to wider chars if needed
typedef uint64_t asbool; // Bools need to be 64 bits.
#define AS_TRUE 1
#define AS_FALSE 0

// Author Script Variables
typedef enum ASType {
  AS_TYPE_NIL = 0,
  AS_TYPE_INTEGER,
  AS_TYPE_FLOAT,
  AS_TYPE_BOOLEAN,
  AS_TYPE_STRING,
  AS_TYPE_OBJECT,
  AS_TYPE_FUNCTION,
  AS_TYPE_EXTERNAL_FUNCTION
} ASType;

typedef union ASVarData {
  ASObj *obj;
  ASFunc *func;
  aschar *str;
  int64_t *value_i;
  double *value_f;
  asbool *value_b;
} ASVarData;

typedef struct ASVar {
  ASVarData data;
  const aschar *name;
  ASType type;
} ASVar;

// Author Script Object
// Constructor
#define asObjCreate(bucket_count) asObjCreateAtMemory(NULL, bucket_count)
ASObj *asObjCreateAtMemory(void *const memory, const size_t bucket_count);
// Destructor - Recursively Frees All Objects (Including Passed In Object)
void asObjDestroy(ASObj *obj);
// Add Member
ASVar *asObjSetVar(ASObj *obj, ASVar var);
// Find Member
ASVar *asObjFindVar(ASObj *obj, const aschar *name);
// Add String - Adds String to Object's String Block So It Will Be Freed Upon Object's Destruction
#define asObjReserveData(obj, data_size) asObjAddData(obj, NULL, data_size)
#define asObjAddString(obj, str) asObjAddData(obj, str, strlen(str) + 1)
void *asObjAddData(ASObj *obj, const void *const data, const size_t data_size);

#ifdef __cplusplus
} // ends extern "C"
#endif

#endif