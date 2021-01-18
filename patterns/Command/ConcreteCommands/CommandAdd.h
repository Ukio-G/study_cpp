//
// Created by ukio on 18.01.2021.
//

#ifndef COMMAND_COMMANDADD_H
#define COMMAND_COMMANDADD_H

#include "Command/Command.h"

class CommandAdd : public Command {
public:
    CommandAdd(int a, int b, int & result);
    void execute();

private:
    int a;
    int b;
    int & result_buffer;
};


#endif //COMMAND_COMMANDADD_H
