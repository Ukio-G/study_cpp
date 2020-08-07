#include <iostream>
int main(int argc, char const *argv[])
{
	int * m = new int(1);

	std::cout << reinterpret_cast<size_t>(m) << std::endl;


	const char * a = "asd";

	char * b = (char *)a;

	b = "a";

	std::cout << a << std::endl;

	return 0;
}