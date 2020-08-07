#include <iostream>
#include <typeinfo>
#include <string>
int main(int argc, char const *argv[])
{
	const int & a = 1;
	auto b = a;

	std::string str = "String";

	std::cout << typeid(a).name() << std::endl;	// i
	std::cout << typeid(b).name() << std::endl; // i
	std::cout << typeid(str[1] + str[2]).name() << std::endl;



	return 0;
}