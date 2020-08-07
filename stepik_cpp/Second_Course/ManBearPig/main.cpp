#include "manpigbear.h"
 
int main(int argc, char const *argv[])
{
    ManBearPig mbp(2);
    // Bear const * pu = &mbp;
    Bear * b = new Bear(1);
    std::string name = b->name();
    std::cout << name << std::endl;
    if (mbp.id() != 456) {}
    return 0;
}