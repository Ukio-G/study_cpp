#include "template.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Array<int> arrayInt(50);
	// arrayInt.get(2) = 10;
	arrayInt[2] = 19;
	std::cout << arrayInt[2] << std::endl;
	return 0;
}