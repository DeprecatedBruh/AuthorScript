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
typedef enum ASType { AS_TYPE_NUMBER = 0, AS_TYPE_STRING, AS_TYPE_OBJECT, AS_TYPE_NIL } ASType;

typedef union ASVarData {
  ASObj *obj;
  const aschar *str;
  int64_t value;
} ASVarData;

typedef struct ASVar {
  const aschar *name;
  ASVarData data;
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
// Add String - Adds String to Object's String Block So It Will Be Freed Upon Destruction
const aschar *asObjAddString(ASObj *obj, const aschar *str);

#endif