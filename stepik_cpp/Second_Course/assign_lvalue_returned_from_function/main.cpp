#include <iostream>
int globalvar = 20;

int& foo()
{
    return globalvar;
}

int main()
{
    foo() = 10;
    std::cout << globalvar << std::endl;
    return 0;
}