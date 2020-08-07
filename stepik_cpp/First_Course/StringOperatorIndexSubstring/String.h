#ifndef __STRING__H_
#define __STRING__H_
#include <cstddef>  // size_t
#include <algorithm>
#include <cstring>  // strlen, strcpy
#include <iostream>
#include <cstdint>




struct String {
  struct Substring;
  String(const char *str = "");
  String(size_t n, char c);
  ~String();

  String(const String &other);
  String &operator=(const String &other);

  // String &operator=(const Substring &other);

  void append(const String &other);

  Substring operator[](int i) const;

  size_t size;
  char *str;

struct Substring
{

	Substring(String const & str,int offset);
	// ~Substring();
  	char *strSubstr;	
  	size_t sizeSubstr;
  	size_t offsetFront;
  	String operator[](int i) const;
};

};



std::ostream &operator<<(std::ostream &os, String const &str);

#endif