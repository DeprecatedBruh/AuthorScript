#ifndef _ASDATA_H_
#define _ASDATA_H_

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// Author Script Object Forward Declaration
struct ASObj;
typedef struct ASObj ASObj;

// Author Script Variables
typedef char aschar; // Makes it slightly easier to switch to wider chars if needed
typedef enum ASType { AS_TYPE_NIL = 0, AS_TYPE_INTEGER, AS_TYPE_FLOAT, AS_TYPE_BOOLEAN, AS_TYPE_STRING, AS_TYPE_OBJECT } ASType;

typedef union ASVarData {
  ASObj *obj;
  const aschar *str;
  int64_t value_i;
  double value_f;
  _Bool value_b;
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
ASVar *asObjAddVar(ASObj *obj, ASVar var);
// Find Member
ASVar *asObjFindVar(ASObj *obj, const aschar *name);
// Add String - Adds String to Object's String Block So It Will Be Freed Upon Object's Destruction
const aschar *asObjAddString(ASObj *obj, const aschar *str);

#endif