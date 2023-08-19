project(exercise_12_2)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SRC_LIST main.cpp string1.cpp)

add_executable(main ${SRC_LIST})