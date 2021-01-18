//
// Created by ukio on 18.01.2021.
//

#include "LambdaCommand.h"

#include <utility>

LambdaCommand::LambdaCommand(commandType action, std::shared_ptr<void> extra_data) :command(std::move(action)), extra_data(std::move(extra_data)){

}

void LambdaCommand::execute() {
    command(extra_data);
}
