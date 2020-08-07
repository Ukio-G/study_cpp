cmake_minimum_required(VERSION 3.15)
project(socket_basic)

set(CMAKE_CXX_STANDARD 11)

add_executable(socket_server ServerSocket.cpp Tracker.h)
add_executable(socket_client SocketClient.cpp Tracker.h)