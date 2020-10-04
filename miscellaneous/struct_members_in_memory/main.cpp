#include <iostream>
#include <cstdint>

struct sDword {
    struct word_1 {
        uint8_t low;
        uint8_t high;
    } sWord1;

    struct word_2 {
        uint8_t low;
        uint8_t high;
    } sWord2;
};

int main()
{
    sDword dword = {{1,2},{3,4}};

    std::cout << (int)dword.sWord1.low << std::endl;
    std::cout << (int)dword.sWord1.high << std::endl;
    std::cout << (int)dword.sWord2.low << std::endl;
    std::cout << (int)dword.sWord2.high << std::endl;

    uint8_t byte_1 = *((uint8_t*)(&dword));
    uint8_t byte_2 = *((uint8_t*)(&dword)+1);
    uint8_t byte_3 = *((uint8_t*)(&dword)+2);
    uint8_t byte_4 = *((uint8_t*)(&dword)+3);
   

    std::cout << (int)byte_1 << std::endl;
    std::cout << (int)byte_2 << std::endl;
    std::cout << (int)byte_3 << std::endl;
    std::cout << (int)byte_4 << std::endl;


    return 0;
}
