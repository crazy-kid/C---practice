project(exercise_11_1)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SRC_LIST vect.cpp randwalk.cpp)

add_executable(randwalk ${SRC_LIST})

