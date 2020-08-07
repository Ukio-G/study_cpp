#include <iostream>
#include <cstddef>
#include <string>

template<class Z, size_t (Z::*)() const = &Z::size>
int get_size(Z & t)
{
    return t.size();
};

template<class Z, size_t (Z::*) = &Z::size>
int get_size(Z & t)
{
    return t.size;
};

struct Struct
{
    size_t size = 0;
};

int main() {


    std::string s{"Hello"};
    s.size();
    std::cout << get_size(s) << std::endl;

    Struct x;
    x.size = 10;
    std::cout << get_size(x) << std::endl;

    return 0;
}
