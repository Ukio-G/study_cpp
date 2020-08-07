#include <type_traits>
#include <typeinfo>
#include <iostream>




template<class T> typename std::remove_reference<T>::type&&
move(T&& arg) {
	typedef typename std::remove_reference<T>::type&& rval;
	rval a((rval)arg);
	std::cout << "arg type " <<  typeid(arg).name() << std::endl;
	std::cout << "a type " <<  typeid(a).name() << std::endl;
	std::cout << std::is_rvalue_reference<rval>::value << std::endl;
	return (rval)a;
}


int main(int argc, char const *argv[])
{
	int a (move(2));
	std::cout << a << std::endl;
	return 0;
}
