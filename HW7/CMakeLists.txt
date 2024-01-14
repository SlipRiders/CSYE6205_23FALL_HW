cmake_minimum_required(VERSION 3.26)
project(HW7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW7
        composition.cpp
        composition.h
        test.cpp)
