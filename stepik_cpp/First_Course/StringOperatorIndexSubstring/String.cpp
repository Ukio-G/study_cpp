#include "String.h"
#include <iostream>

String::String(const char *str) : size(strlen(str)), str(new char[size + 1]) {
  strcpy(this->str, str);
  this->str[size] = '\0';
  // std::cout << "const char constructor of " << this << " from " << &str << std::endl;
}

String::String(String const &str) {
  this->size = str.size;
  this->str = new char[size + 1];
  strcpy(this->str, str.str);
  this->str[size] = '\0';
  // std::cout << "const string constructor of " << this << " from " << &str << std::endl;
}

String::String(size_t n, char c) : size(n), str(new char[size + 1]) {
  for (int i = 0; i < n; ++i) str[i] = c;
  str[size] = '\0';
}

String::~String() { delete[] str; }

String & String::operator=(const String &other) {
  delete[] this->str;
  str = new char[other.size];
  strcpy(this->str, other.str);
  this->str[size] = '\0';
  this->size = other.size;
  // std::cout << "equal operator called" << std::endl;
  return *this;
}

// String & String::operator=(const String::Substring &other) {
//   delete[] this->str;
//   str = new char[other.size];
//   strcpy(this->str, other.str);
//   this->str[size] = '\0';
//   this->size = other.size;
//   std::cout << "equal substring operator called" << std::endl;
//   return *this;
// }


void String::append(const String &other) {
  size_t new_size = this->size + other.size;
  char *new_string = new char[size + 1];
  strcpy(new_string, this->str);
  strcpy(new_string + this->size, other.str);
  new_string[new_size] = '\0';

  delete[] str;

  this->str = new_string;
  this->size = new_size;
}

String::Substring::Substring(String const & str, int offset): offsetFront(offset)
{
  // std::cout << "substr ctor called" << std::endl;

  this->strSubstr = new ((str.str)+offset) char;
  this->sizeSubstr = str.size - offsetFront;

  // std::cout << "new substr strSubstr is " << this->strSubstr << " and size is " << str.size<<std::endl;
}

String::Substring String::operator[](int i) const {
  Substring substring(*this,i);
  return substring;
}

String String::Substring::operator[](int i) const{
  int diffPosition = i-this->offsetFront;
  // std::cout << diffPosition << std::endl;
 // this->strSubstr[di]
 // memcpy(newStr,this->strSubstr,sizeof(char)*(diffPosition));
 this->strSubstr[diffPosition] = '\0';
 return String(this->strSubstr);     
}

std::ostream &operator<<(std::ostream &os, String const &str) {  return os << str.str; }