cmake_minimum_required(VERSION 4.2)
project(DoublyLinkedList C)

set(CMAKE_C_STANDARD 23)

add_executable(DoublyLinkedList
    Main.c
    DoublyLinkedList.c
    DoublyLinkedList.h
)
