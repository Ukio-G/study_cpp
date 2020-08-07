#include <iostream>

#include <cstddef> // size_t



template <typename t, size_t n> size_t array_size (t (&a)[n])
{
  return n;
}
int main(int argc, char const *argv[])
{
int ints[] = {1, 2, 3, 4};
// int *iptr = ints;
double doubles[] = {3.14};
std::cout << array_size(ints) << std::endl;; // вернет 4
std::cout <<  array_size(doubles) << std::endl; // вернет 1
// array_size(iptr); // тут должна произойти ошибка компиляци	
	return 0;
}
