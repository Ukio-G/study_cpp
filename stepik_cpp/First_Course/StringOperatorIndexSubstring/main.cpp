#include <iostream>
#include "String.h"

int main(int argc, char const *argv[]) {
  String const hello("hello");
  String const hell = hello[0][4];  // теперь в hell хранится подстрока "hell"
  String const ell = hello[1][4];  // теперь в ell хранится подстрока "ell"
  String const empty = hello[5][5];  // теперь в ell хранится подстрока "ell"
  std::cout <<"hell variable is " << hell << std::endl;
  std::cout << "ell variable is " << ell << std::endl;
  std::cout << "empty is " << empty << std::endl;
  return 0;
}
