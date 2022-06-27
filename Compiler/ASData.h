#ifndef _ASDATA_H_
#define _ASDATA_H_

// std
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus // C++ Stuff
#define _Bool bool

extern "C" {
#else // C Stuff
#include <stdalign.h>

#define true 1
#define false 0
#endif

// Author Script Object Forward Declaration
struct ASObj;
typedef struct ASObj ASObj;

// Author Script Variables
typedef char aschar; // Makes it slightly easier to switch to wider chars if needed
typedef uint64_t asbool;
typedef enum ASType { AS_TYPE_NIL = 0, AS_TYPE_INTEGER, AS_TYPE_FLOAT, AS_TYPE_BOOLEAN, AS_TYPE_STRING, AS_TYPE_OBJECT } ASType;

typedef union ASVarData {
  ASObj *obj;
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
ASObj *asObjCreate(const size_t bucket_count);
// Destructor - Recursively Frees All Objects (Including Passed In Object)
void asObjDestroy(ASObj *obj);
// Add Member
ASVar *asObjSetVar(ASObj *obj, ASVar var);
// Find Member
ASVar *asObjFindVar(ASObj *obj, const aschar *name);
// Add String - Adds String to Object's String Block So It Will Be Freed Upon Object's Destruction
#define asObjAddString(obj, str) asObjAddData(obj, str, strlen(str) + 1)
void *asObjAddData(ASObj *obj, const void *const data, const size_t data_size);

#ifdef __cplusplus
} // ends extern "C"
#endif

#endif