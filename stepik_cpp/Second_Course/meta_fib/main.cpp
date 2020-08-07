#include <iostream>

template<int V>
struct Fib
{
    static int const value = V + Fib<V-1>::value;
};

template<>
struct Fib<1>
{
    static int const value = 1;
};

template<>
struct Fib<0>
{
    static int const value = 1;
};

int main() {
    std::cout << Fib<10>::value << std::endl;
    return 0;
}
