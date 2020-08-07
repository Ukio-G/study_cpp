#include <iostream>

struct StructMultupleDef
{
	StructMultupleDef(){std::cout << "ctor" << std::endl;}
	int i;
	char c;
    void method() {i = 20;}	
};