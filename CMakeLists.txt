cmake_minimum_required(VERSION 3.19)
project(Sorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sorts main.cpp DynamicArray.h DynamicArray.cpp DynamicArraySequence.h LinkedList.cpp LinkedList.h LinkedListSequence.h Sequence.h Sorts.cpp Sorts.h)