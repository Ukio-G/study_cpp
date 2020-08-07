#include <algorithm>
#include <cstddef>  // size_t
#include <cstring>  // strlen, strcpy
#include <iostream>

struct String {
  String(const char *str = "");
  String(size_t n, char c);
  String(String const &str);

  /* и деструктор */
  ~String();

  void printStr();
  size_t size;
  char *str;
};

String::String(String const &str) {
  this->size = str.size;
  this->str = new char[size + 1];
  strcpy(this->str, str.str);
  this->str[size] = '\0';
}

String::~String() { delete[] str; }

String::String(size_t n, char c) : size(n), str(new char[size + 1]) {
  for (int i = 0; i < n; ++i) str[i] = c;
  str[size] = '\0';
}

String::String(const char *str) : size(strlen(str)), str(new char[size + 1]) {
  strcpy(this->str, str);
  this->str[size] = '\0';
}

int main(int argc, char const *argv[]) {
  String s = "123";
  String s2 = s;

  std::cout << s2.str << std::endl;
  return 0;
}