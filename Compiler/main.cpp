// std
#include <stdio.h>
#include <string.h>

#include "ASData.h"
#include "ASParserVisitorImpl.hpp"

int main(int argc, char *argv[]) {
  if(argc < 2)
    return 1;

  ASObj *obj = asObjCreate(32);
  asRunParser(obj, argv[1]);
  asObjDestroy(obj);

  return 0;
}