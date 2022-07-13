#ifndef _ASFUNC_H_
#define _ASFUNC_H_

// AuthorScript
#include "ASData.h"

#ifdef __cplusplus
// C++ Stuff
extern "C" { // wraps C code for the sake of C++ includes
#endif

// Author Script Function Forward Declaration
struct ASFunc;
typedef struct ASFunc ASFunc;

// Author Script Function
// Constructor
ASFunc *asFuncCreate();
// Destructor
void asFuncDestroy(ASFunc *const func);
// Getters
#define asFuncGetVarsObj(func) ((ASObj *)func)

#ifdef __cplusplus // ends extern "C"
}
#endif

#endif // _ASFUNC_H_