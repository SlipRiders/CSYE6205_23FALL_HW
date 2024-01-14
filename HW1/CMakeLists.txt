cmake_minimum_required(VERSION 3.26)
project(s)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(s
        p2.cpp
        p2.h
        p2test.cpp)
