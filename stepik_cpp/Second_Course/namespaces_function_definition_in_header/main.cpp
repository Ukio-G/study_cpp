#include "test.h"
void abc();

int main(int argc, char const *argv[])
{

	void (*b)() = &foo;
	abc();

	std::cout << &a << std::endl;
	return 0;
}