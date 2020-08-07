#include <iostream>


int main(int argc, const char *argv[])
{
    
    int intVariable = 10;

    int * ptrInt = &intVariable;

    int const ** constPtrPtr = &ptrInt;
    
    std::cout << intVariable << std::endl;

    return 0;
}
