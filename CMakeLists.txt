cmake_minimum_required(VERSION 3.7)
project(Wet2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES Tree.h main.cpp Execptions.h Heap.h List.h ChainHash.h)
add_executable(Wet2 ${SOURCE_FILES})