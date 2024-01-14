cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "g++")

project(AOC)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(d2p1 d2p1.cpp)
add_executable(d2p2 d2p2.cpp)
