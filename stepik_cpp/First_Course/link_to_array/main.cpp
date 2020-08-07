#include <iostream>

void foo(int (&a)[50])
{
    std::cout << a[0] << std::endl;
}

int main(int argc, const char *argv[])
{
    int a[50] = {};
    foo(a);
    return 0;
}
