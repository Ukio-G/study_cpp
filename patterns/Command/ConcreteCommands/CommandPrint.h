//
// Created by ukio on 18.01.2021.
//

#ifndef COMMAND_COMMANDPRINT_H
#define COMMAND_COMMANDPRINT_H

#include <string>
#include "Command/Command.h"

class CommandPrint : public Command {
public:
    CommandPrint(std::string & string);
    void execute();
private:
    std::string string; // Yep, i want to keep copy
};


#endif //COMMAND_COMMANDPRINT_H
