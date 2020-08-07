#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size) {
  char *new_str = new char[new_size];
  for (unsigned int i = 0; size > i && new_size > i; i++) {
    new_str[i] = str[i];
  }
  delete[] str;
  return new_str;
}

int main(int argc, const char *argv[]) {
  char *str = new char[20];
  char *new_str = resize(str, 20, 2);

  std::cout << new_str << std::endl;
  delete[] new_str;
  return 0;
}
