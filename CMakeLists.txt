cmake_minimum_required(VERSION 3.19)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        main.cpp BinaryTree.cpp)

add_executable(bt_sp main2.cpp)