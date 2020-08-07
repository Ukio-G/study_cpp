#include <iostream>
#include <typeinfo>

void print_values(std::ostream & os) {}
template<typename T>
void print_values(std::ostream & os, T value)
{
	os << typeid(value).name() << ": " << value << std::endl;
}

template<typename T, typename... Ts>
void print_values(std::ostream & os, T value, Ts... arg) 
{
	os << typeid(value).name() << ": " << value << std::endl;
	print_values(os,arg...);
}


int main(int argc, char const *argv[])
{
	print_values(std::cout, 0, 3.5, "Hello");
	return 0;
}


