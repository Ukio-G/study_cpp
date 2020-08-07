#include <iostream>
namespace {
	void foo()
	{
		std::cout << "foo called" << std::endl;
	}

	static void bar()
	{

		std::cout << "bar called" << std::endl;
	}

	

	int a = 2;
}