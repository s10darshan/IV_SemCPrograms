cmake_minimum_required(VERSION 4.2)
project(Priority_Queue C)

set(CMAKE_C_STANDARD 23)

add_executable(Priority_Queue main.c
        PriorityQueue.c
        PriorityQueue.h)
