#include <type_traits>
#include <iostream>
#include <utility>


template<class T>
T&& forward(typename std::remove_reference<T>::type& arg) {
	std::cout << std::is_rvalue_reference<T>::value << std::endl;
	std::cout << std::is_rvalue_reference<T&&>::value << std::endl;
	return static_cast<T&&>(arg);
}

int main(int argc, char const *argv[])
{

	int a = 1;
	int & b = a;
	forward<int>(a);
	forward<int&>(b);
	return 0;
}