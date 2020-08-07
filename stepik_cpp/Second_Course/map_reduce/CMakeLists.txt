cmake_minimum_required(VERSION 3.16)
project(map_reduce)

set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(map_reduce main.cpp)

target_link_libraries(map_reduce Threads::Threads)