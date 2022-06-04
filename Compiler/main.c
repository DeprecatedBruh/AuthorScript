#include <stdio.h>

#include "ASData.h"

int main(int argc, char *argv[]) {
  ASObj *obj = asObjCreate(12);
  asObjDestroy(obj);
  return 0;
}