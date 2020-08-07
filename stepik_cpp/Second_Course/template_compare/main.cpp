#include <iostream>
#include <string>


template<typename T, typename T2>
bool compare(T const & a, T const & b, T2 (T::*mptr)() const) {
	if((a.*mptr)() >= (b.*mptr)())
		return false;
		return true;
}

int main(int argc, char const *argv[])
{
	std::string s1("Elf");
	std::string s2("Archer");

// сравнение строк по длине
	bool r1 = compare(s1, s2, &std::string::size); // true
	bool r2 = compare(s1, s1, &std::string::size); // false

	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;

	return 0;
}
