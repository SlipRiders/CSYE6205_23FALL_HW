cmake_minimum_required(VERSION 3.26)
project(HW2_Xiaoyang_Chen)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW2_Xiaoyang_Chen
        ninetynine.cpp
        ninetynine.h
        ninetyninepointerbased.cpp
        ninetyninereferencebased.cpp
        ninetyninetest.cpp)
