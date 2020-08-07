#include <iostream>
 

struct Cls {
Cls(char c, double d, int i);
	char getC();
	double getD();
	int getI();
private:
    char c;
    double d;
    int i;
};

Cls::Cls(char c, double d, int i) : c(c), d(d), i(i) {}
int Cls::getI(){return i;}
double Cls::getD(){return d;}
char Cls::getC(){return c;}

// // Эта функция должна предоставить доступ к полю c объекта cls.
// // Обратите внимание, что возвращается ссылка на char, т. е.
// // доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
char & ch = *((char*)&cls);
return ch;
}

// // Эта функция должна предоставить доступ к полю d объекта cls.
// // Обратите внимание, что возвращается ссылка на double, т. е.
// // доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
char * cls_start = (char*)&cls;
double & d = *((double*)(cls_start+8));
return d;
}

// // Эта функция должна предоставить доступ к полю i объекта cls.
// // Обратите внимание, что возвращается ссылка на int, т. е.
// // доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
char * cls_start = (char*)&cls;
int & i = *((int*)(cls_start+16));
return i;
}

int main(int argc, char const *argv[])
{
	Cls object('a',20.0,22);
	Cls & link = object;
	std::cout << "Size " << sizeof(object) << " Adress " << &object << std::endl;
	std::cout << "Size char "<<  sizeof(char) << std::endl;
	std::cout << "Size int "<<  sizeof(int) << std::endl;
	std::cout << "Size double "<<  sizeof(double) << std::endl;

	// char & ch = *((char*)&link);
	// double * d = reinterpret_cast<double *>(ch+sizeof(double));
	// int * i = reinterpret_cast<int *>(ch+sizeof(double)*2);
	// std::cout << ch << std::endl;
	// std::cout << *d << std::endl;
	// std::cout << *i << std::endl;
	
	// ch = 'b';


	char & ch = get_c(object);
	int & i = get_i(object);
	double & d = get_d(object);

	ch = 'b';
	i=200;
	std::cout << object.getC() << std::endl;
	std::cout << object.getI() << std::endl;
	std::cout << d << std::endl;

	return 0;
}