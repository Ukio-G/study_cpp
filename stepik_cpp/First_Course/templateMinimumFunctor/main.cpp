#include <iostream>
#include "template_array.h"

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

template<typename T,typename Comp>
T minimum(Array<T> const & array,Comp c) {
	T result = array[0];
	for (int i = 0; i < array.size(); ++i)
		if(c(array[i],result)) result = array[i];
	return result;
}

int main(int argc, char const *argv[])
{
	Array<int> ints(5);
ints[0] = 10;
ints[1] = 2;
ints[2] = 15;
ints[3] = 1;
ints[4] = 152;
// minimum(ints,functionTemplate);
int min = minimum(ints, less); // в min должно попасть число 2
int max = minimum(ints, Greater()); // в max должно попасть число 15
std::cout << min << std::endl;
std::cout << max << std::endl;

	return 0;
}