#include <iostream>

template<int ... T>
struct IntList;

template<int H, int... T>
struct IntList<H, T...>
{
    static int const Head = H;
    using Tail = IntList<T...>;
};


template<>
struct IntList<>
{

};

template<typename List>
struct Length
{
    static int const value = 1 + Length<typename List::Tail>::value;
};

template<>
struct Length<IntList<>>
{
    static int const value = 0;
};

int main() {

    using primes = IntList<2,3,5,7,11,13>;

    constexpr int head = primes::Head;

    using odd_primes = primes::Tail;


    std::cout << Length<primes>::value << std::endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
