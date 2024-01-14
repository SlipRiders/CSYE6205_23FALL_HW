cmake_minimum_required(VERSION 3.26)
project(slist)

set(CMAKE_CXX_STANDARD 14)

include_directories(s)

add_executable(slist
        s/slist1.cpp
        s/slist1.h
        s/slist1test.cpp
)
