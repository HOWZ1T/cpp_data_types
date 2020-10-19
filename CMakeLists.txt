cmake_minimum_required(VERSION 3.15)
project(data_structures)

set(CMAKE_CXX_STANDARD 17)

# set the source files for the project
set(SOURCE_FILES unit_tests.cpp ArrayStack.cpp ArrayStack.h)

# includes the Catch2 header library for creating unit tests
include_directories(Catch2)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})