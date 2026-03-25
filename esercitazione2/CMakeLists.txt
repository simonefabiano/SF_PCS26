cmake_minimum_required(VERSION 3.20)

project(esercitazione2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(memoria_oggetti memoria_oggetti.cpp)
add_executable(primi_algoritmi primi_algoritmi.cpp)