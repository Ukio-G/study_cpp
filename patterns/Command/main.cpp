#include <iostream>
#include <memory>
#include "Logic.h"
#include "CommandAdd.h"
#include "Command/CommandExecutor.h"
#include "CommandSaveToFile.h"
#include "CommandPrint.h"
#include "LambdaCommand.h"

int main() {
    Logic::init();
    Logic & l = *Logic::get();

    l.open_stream(std::string("result"));
    int result;

    CommandExecutor executor;

    executor.setCommand(std::make_shared<CommandAdd>(5, 3, result));
    executor.execute_command();

    executor.setCommand(
            std::make_shared<LambdaCommand>([](std::shared_ptr<void> & extra_data){
                void * void_ptr = (void *)extra_data.get();
                int *i = (int*)void_ptr;
                std::cout << "lambda printer " << *i << std::endl;
            }, std::make_shared<int>(result)));
    executor.execute_command();

    executor.setCommand(std::make_shared<CommandSaveToFile>(std::to_string(result)));
    executor.execute_command();

    return 0;
}
