cmake_minimum_required(VERSION 3.7)
project(Wet2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES ChainHash.cpp ChainHash.h Execptions.h Heap.h library2.cpp library2.h List.h main.cpp
        Oasis.h Oasis.cpp PlayerClan.h PlayerClan.cpp RankTree.h Tree.h)
add_executable(Wet2 ${SOURCE_FILES})