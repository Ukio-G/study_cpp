#include <iostream>

#include "../ManBearPig/manpigbear.h"
#include <typeinfo>

// возвращает true, если p и q указывают на один и тот же объект
template<class T>
bool isSameObject(T const * p, T const * q)
{
	if (dynamic_cast<void const *>(p) == dynamic_cast<void const *>(q))
		return true;
	return false;
}


int main(int argc, char const *argv[])
{
	ManBearPig * mbp1 = new ManBearPig(1);
	Unit * u = mbp1;
	
	std::cout << isSameObject<Animal>(static_cast<Bear const*>(mbp1), static_cast<Pig const*>(mbp1))  << std::endl;

	return 0;
}