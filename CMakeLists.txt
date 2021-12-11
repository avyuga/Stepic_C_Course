cmake_minimum_required(VERSION 3.20)
project(Stepic_C_Course C)

set(CMAKE_C_STANDARD 11)

include_directories(arrays)
include_directories("linked lists")

add_executable(Stepic_C_Course
        arrays/array.c
        arrays/array.h
        "linked lists/linked_list.c"
        "linked lists/linked_list.h"
        main.c arrays/array_array.h arrays/array_array.c)

