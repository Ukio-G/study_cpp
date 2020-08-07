cmake_minimum_required(VERSION 3.16)
project(map_reduce_thread)

set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(map_reduce_thread main.cpp)

target_link_libraries(map_reduce_thread Threads::Threads)

