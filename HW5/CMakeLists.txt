cmake_minimum_required(VERSION 3.26)
project(HW5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW5
        String2Data.cpp
        String2Data.h
        String2DataTest.cpp
        util.h)
