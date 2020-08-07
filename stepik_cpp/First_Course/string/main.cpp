#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	size_t size;
	char *str;
};

String::String(const char *str) : size(strlen(str)), str(new char[size+1]){
	strcpy(this->str,str);
	this->str[size] = '\0';
}

int main(int argc, char const *argv[])
{
	String str = "C-style string";

	return 0;
}