cmake_minimum_required(VERSION 3.16)
project(BaseMediator)

set(CMAKE_CXX_STANDARD 14)

file(GLOB BaseMediator_SRC
        "Model/*.h"
        "Model/*.cpp"
        )

include_directories(Model)
include_regular_expression(Model/*.cpp)
include_regular_expression(Model/*.h)

add_executable(BaseMediator main.cpp ${BaseMediator_SRC})
