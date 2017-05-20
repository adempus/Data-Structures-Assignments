cmake_minimum_required(VERSION 3.5)
project(Homework2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ContactList.h ContactList.cpp Contact.h Contact.cpp)
add_executable(Homework2 ${SOURCE_FILES})