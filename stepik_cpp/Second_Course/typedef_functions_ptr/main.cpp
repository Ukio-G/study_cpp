

// При помощи typedef определите тип ComplexFunction, 
// который является указателем на функцию,
// которая принимает int и 
// указатель  на функцию, принимающую double и возвращающую int, 
// и возвращает указатель на функцию, которая принимает char const * и возвращает int *.


typedef int (*f_function) (double);
typedef int * (*s_function) (char const*);
 
typedef s_function (*ComplexFunction)(int,f_function);


int main(int argc, char const *argv[])
{
	
	return 0;
}
