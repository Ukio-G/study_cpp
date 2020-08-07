#include <iostream>

#include <functional>

void ff(int * a)
{
	*a +=10;
}

int main(int argc, char const *argv[])
{
	

	int * i = new int;

	*i = 10;

	int result = 0;


	void (*f)(int&) = [](int &arg){arg+=10;};

	f(*i);

	std::cout << *i << std::endl;


	std::function<void (int &)> catching_function = [&](int & arg){result += arg;};


	catching_function(*i);

	std::cout << result << std::endl;

	return 0;
}