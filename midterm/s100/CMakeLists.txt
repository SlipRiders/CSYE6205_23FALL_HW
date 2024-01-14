cmake_minimum_required(VERSION 3.26)
project(s100)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(s100
        magicsquare.cpp
        magicsquare.h
        magicsquaretest.cpp)
