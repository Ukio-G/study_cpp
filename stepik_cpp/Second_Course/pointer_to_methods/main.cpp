#include <iostream>

struct S
{
	S(unsigned int value) : value(value) {}

	unsigned int m() const{
		return this->value;
	}

	unsigned int value;
};

typedef unsigned int (S::*s_method)() const;

bool function(int value, s_method value_get, S object)
{
	if(static_cast<unsigned int>(value) == (object.*value_get)()) return true; 
	return false;
}

int main(int argc, char const *argv[])
{
	S object(2);
	std::cout << function(1,&S::m,object)  << std::endl;
	std::cout << function(2,&S::m,object)  << std::endl;
	return 0;
}