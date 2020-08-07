#include <iostream>

template<typename T,typename U>
void copy_n(U * dest, T * source, int count) {
	for (int i = 0; i < count; ++i)
		dest[i] = static_cast<U>(source[i]);
}


int main(int argc, char const *argv[]) {
  int ints[] = {1, 2, 3, 4};
  double doubles[4] = {};
  copy_n(
      doubles, ints,
      4);  // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0

  std::cout << doubles[0] << std::endl;
  return 0;
}