//
// Created by ukio on 18.01.2021.
//

#ifndef COMMAND_LAMBDACOMMAND_H
#define COMMAND_LAMBDACOMMAND_H


#include <Command/Command.h>
#include <functional>
#include <memory>

class LambdaCommand : public Command {
public:
    using commandType = std::function<void(std::shared_ptr<void> & extra_data)>;
    explicit LambdaCommand(commandType action, std::shared_ptr<void> extra_data = nullptr);

    std::shared_ptr<void> extra_data;
    LambdaCommand() = delete;
    void execute();
private:
    commandType command;
};


#endif //COMMAND_LAMBDACOMMAND_H
