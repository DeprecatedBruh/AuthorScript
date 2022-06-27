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

  ASObj *a = asObjFindVar(obj, "a")->data.obj;
  ASVar *b = asObjFindVar(a, "b");
  ASVar *c = asObjFindVar(a, "c");
  ASVar *g = asObjFindVar(a, "g");
  printf("B: \"%s\"\n", b->data.str);
  printf("C: %f\n", *c->data.value_f);
  printf("G: \"%s\"\n", g->data.str);

  asObjDestroy(obj);
  return 0;
}