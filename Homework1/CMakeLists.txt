cmake_minimum_required(VERSION 3.5)
project(Contact)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES useContact.cpp Contact.h Contact.cpp)
add_executable(Contact ${SOURCE_FILES})