cmake_minimum_required(VERSION 3.29)
project(LRU)

set(CMAKE_CXX_STANDARD 20)

add_executable(LRU main.cpp
        LRUCache.h
        LRUCache.tpp)
