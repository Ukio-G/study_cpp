#ifndef COMMAND_COMMANDSAVETOFILE_H
#define COMMAND_COMMANDSAVETOFILE_H

#include <Command/Command.h>
#include <cstdio>
#include <ostream>
#include <Logic.h>

class CommandSaveToFile : public Command {
public:
    CommandSaveToFile(const std::string & content);
    void execute();

private:
    std::string content;
};


#endif //COMMAND_COMMANDSAVETOFILE_H
