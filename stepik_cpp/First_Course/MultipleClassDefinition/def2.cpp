#include <iostream>

struct StructMultupleDef {
  StructMultupleDef() { std::cout << "ctor" << std::endl; }
  char c;
  void method() { c = 10; }
};