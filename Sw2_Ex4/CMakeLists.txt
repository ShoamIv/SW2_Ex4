cmake_minimum_required(VERSION 3.28)
project(Sw2_Ex4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sw2_Ex4 main.cpp
        KaryTree.hpp
        Node.hpp
        InorderIterator.hpp
        PreorderIterator.hpp
        PostorderIterator.hpp
        BfsIterator.hpp
        DfsIterator.hpp
        HeapIterator.hpp
)
