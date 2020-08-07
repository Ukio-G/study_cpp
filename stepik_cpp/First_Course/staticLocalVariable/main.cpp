#include <iostream>

int next(int);
int main(int argc, char const *argv[])
{
	std::cout << next(20) << std::endl;
	std::cout << next(10) << std::endl;
	return 0;
}

int next(int number){
static int i = number;
return i++;
}