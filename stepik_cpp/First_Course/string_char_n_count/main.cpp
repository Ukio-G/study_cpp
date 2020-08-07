#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	
	String(const char *str = "");
	String(size_t n, char c);

	void append(String &other);
    /* и деструктор */
	~String();

	void printStr();
	size_t size;
	char *str;
};

String::~String(){
	delete [] str;
	
}

String::String(size_t n, char c): size(n),str(new char [size+1])
{
	for (int i = 0; i < n; ++i)
		str[i] = c;
	str[size] = '\0';
}

String::String(const char *str) : size(strlen(str)), str(new char[size+1]){
	strcpy(this->str,str);
	this->str[size] = '\0';
}

void String::printStr()
{
	std::cout << str << std::endl;
}

void String::append(String &other)
{
	size_t new_size = this->size+other.size;
	char * new_string = new char[size+1];
	strcpy(new_string,this->str);
	strcpy(new_string+this->size,other.str);
	new_string[new_size] = '\0';

	delete [] str;

	this->str = new_string;
	this->size = new_size;
}



int main(int argc, char const *argv[])
{
	String str(10,'c');
	String str2 = "string 2";

	str.append(str2);

	str.printStr();

	String s("Hello");
	s.append(s); // теперь s хранит "HelloHello"
	
	s.printStr();
	return 0;
}