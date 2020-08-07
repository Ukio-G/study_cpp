#include "template.h"
#include <iostream>
struct NoCtorType {
	NoCtorType(const NoCtorType &other) : i(other.i), c(other.c), d(other.d) {}
  int i;
  char c;
  double d;
};

int main(int argc, char const *argv[])
{


	NoCtorType* noCtorObject = (NoCtorType*) ::operator new (sizeof(NoCtorType));
	noCtorObject->i = 10;
	noCtorObject->d = 20.2f;
	noCtorObject->c = 'c';

	int count = 10;
 
 	Array<NoCtorType> noCtorMemory(10,*noCtorObject);


for (int i = 0; i < count; ++i)
{
	std::cout << "noCtorMemory#" <<i << " = " <<noCtorMemory[i].i << std::endl;
}
 	 


  return 0;
}