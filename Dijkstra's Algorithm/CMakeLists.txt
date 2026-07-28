cmake_minimum_required(VERSION 4.3.0)
project(Dijkstra_Algorithm)

set(CMAKE_C_STANDARD 23)

add_executable(Dijkstra_Algorithm 
                main.c
                Graph.c
                Graph.h
                MinPriorityQ.c
                MinPriorityQ.h
                Dijkstra.c
                Dijkstra.h
)