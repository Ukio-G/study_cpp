cmake_minimum_required(VERSION 3.16)
project(ChainofResponsibilityPointsAdder)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChainofResponsibilityPointsAdder main.cpp AddPointHandler.cpp AddPointHandler.h Basics.h Tracks.cpp Tracks.h)