//
// Created by ukio on 18.01.2021.
//

#ifndef COMMAND_COMMANDEXECUTOR_H
#define COMMAND_COMMANDEXECUTOR_H

#include <memory>
#include "Command.h"

class CommandExecutor{
public:
    CommandExecutor();
    void setCommand(std::shared_ptr<Command> command);
    void execute_command();
private:
    std::shared_ptr<Command> command;
};


#endif //COMMAND_COMMANDEXECUTOR_H
