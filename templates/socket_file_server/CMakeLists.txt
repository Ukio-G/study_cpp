cmake_minimum_required(VERSION 3.16)
project(socket_file_server)

set(CMAKE_CXX_STANDARD 14)

add_executable(socket_file_server main.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(socket_file_server PRIVATE Threads::Threads)