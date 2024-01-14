cmake_minimum_required(VERSION 3.26)
project(HW8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW8
        sarray.cpp
        sarray.h
        sarraytest.cpp)
