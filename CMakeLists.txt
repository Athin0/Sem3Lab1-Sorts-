cmake_minimum_required(VERSION 3.19)
project(Sorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Sorts
        main.cpp
        DynamicArray.cpp
        LinkedList.cpp
        Sorts.cpp
        Menu.cpp
        baseFunc.cpp
        Compare.cpp Compare.h)