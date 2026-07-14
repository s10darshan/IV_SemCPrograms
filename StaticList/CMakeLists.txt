cmake_minimum_required(VERSION 4.2)
project(StaticList C)

set(CMAKE_C_STANDARD 23)

add_executable(StaticList Main.c
        StaticList.c
        StaticList.h)
