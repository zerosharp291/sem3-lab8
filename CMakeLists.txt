cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

project(lab8)

add_executable(
    run
    src/task1.cpp
    src/passenger.cpp
)

