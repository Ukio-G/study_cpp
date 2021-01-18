//
// Created by ukio on 18.01.2021.
//

#include "CommandExecutor.h"

CommandExecutor::CommandExecutor() : command(nullptr) { }

void CommandExecutor::setCommand(std::shared_ptr<Command> command) {
    this->command = command;
}

void CommandExecutor::execute_command() {
    if(command != nullptr)
        command->execute();
}


