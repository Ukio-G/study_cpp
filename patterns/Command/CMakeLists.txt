cmake_minimum_required(VERSION 3.16)
project(Command)

set(CMAKE_CXX_STANDARD 11)



add_executable(Command main.cpp
        Command/CommandExecutor.cpp
        Command/CommandExecutor.h
        Command/Command.h
        ConcreteCommands/CommandPrint.cpp
        ConcreteCommands/CommandPrint.h
        ConcreteCommands/CommandAdd.cpp
        ConcreteCommands/CommandAdd.h
        ConcreteCommands/CommandSaveToFile.cpp
        ConcreteCommands/CommandSaveToFile.h Logic.cpp Logic.h ConcreteCommands/LambdaCommand.cpp ConcreteCommands/LambdaCommand.h)

target_include_directories(Command PUBLIC .)
target_include_directories(Command PUBLIC ConcreteCommands)
