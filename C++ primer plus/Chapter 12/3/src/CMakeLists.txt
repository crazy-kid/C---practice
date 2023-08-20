project(exercise_12_3)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SRC_LIST stock20.cpp usestok2.cpp)

add_executable(main ${SRC_LIST})