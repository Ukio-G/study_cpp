#include "template_array.h"
#include <iostream>


template<typename T>
void flatten(T const & object, std::ostream & out) noexcept {
	out << object <<std::endl;
}
template<typename T>
std::ostream & operator<<(std::ostream &os,Array<T> array)
{
	for (int i = 0; i < array.size(); ++i)
	{
		os << array[i] << " ";
	}
    return os;
}

int main(int argc, char const *argv[]) {
  Array<int> ints(3, 0);
  ints[0] = 10;
  ints[1] = 20;
  ints[2] = 30;
  // flatten(ints, std::cout);  // выводит на экран строку "10 20"

  Array<Array<int> > array_of_ints(2, ints);
  flatten(array_of_ints, std::cout);  // выводит на экран строку "10 20 10 20"

  // std::cout << array_of_ints << std::endl;
  // std::cout << array_of_ints[1][2] << std::endl;

  return 0;
}