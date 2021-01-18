//
// Created by ukio on 18.01.2021.
//

#include <iostream>
#include "CommandPrint.h"

CommandPrint::CommandPrint(std::string & string) : string(string)
{ }

void CommandPrint::execute() {
    std::cout << string << std::endl;
}
