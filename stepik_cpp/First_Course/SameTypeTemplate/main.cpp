#include <iostream>
struct Dummy {};
typedef int type;

template<class T, class Y>
class SameType {
public:
	static const bool value = false; 
};

template<class T>
class SameType<T,T> {
public:
	static const bool value = true; 
};

// template<class T, class Y>
// class SameType {
// 	static const bool = false;
// };
int main(int argc, char const *argv[]) {
  std::cout << SameType<int, int>::value << std::endl;  // выведет 1, т. е. true
  std::cout << SameType<int, type>::value << std::endl;  // 1, type == int
  std::cout << SameType<int, int &>::value
            << std::endl;  // 0, int и ссылка на int - различные типы
  std::cout << SameType<Dummy, Dummy>::value << std::endl;  // 1
  std::cout << SameType<int, const int>::value
            << std::endl;  // 0, const - часть типа
  return 0;
}
