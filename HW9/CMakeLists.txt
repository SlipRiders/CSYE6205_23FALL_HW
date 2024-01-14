cmake_minimum_required(VERSION 3.26)
project(HW9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW9
        basepluscommissionemployee.h
        commissionemployee.h
        employee.h
        salariedemployee.h
        test.cpp)
