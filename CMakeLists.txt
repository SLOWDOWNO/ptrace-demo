cmake_minimum_required(VERSION 3.0)
project(ptrace_demo)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "-Wall")

add_executable(pro_1 pro_1.c)
add_executable(pro_2 pro_2.c)
add_executable(pro_3 pro_3.c)