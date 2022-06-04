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

typedef struct ASVar {
  // Name of Variable
  aschar *name;
  // Value
  union {
    ASObj *obj;
    aschar *str;
    int64_t value;
  } data;
  // Variable Type
  ASType type;
} ASVar;

// Author Script Object
// TODO: Create a way to safely delete all allocated data by passing obj pointer to a "destructor"
// Constructor
ASObj *asObjCreate(const size_t bucket_count);
// Add Member
ASVar *asObjAddVar(ASObj *obj, ASVar var);
// Find Member
ASVar *asObjFindVar(ASObj *obj, const aschar *name);

#endif