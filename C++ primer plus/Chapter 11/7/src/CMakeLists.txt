project(exercise_11_7)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SRC_LIST complex.cpp main.cpp)

add_executable(main ${SRC_LIST})