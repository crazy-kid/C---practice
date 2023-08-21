project(exercise_13_2)

set(cmake_minimum_required(VERSION 3.15))

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SRC_LIST main.cpp cd.cpp classic.cpp)

add_executable(main ${SRC_LIST})