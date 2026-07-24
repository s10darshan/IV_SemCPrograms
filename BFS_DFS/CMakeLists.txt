cmake_minimum_required(VERSION 4.2)
project(BFS_DFS C)

set (CMAKE_C_STANDARD 23)

add_executable(BFS_DFS Main.c
                Queue.c
                bfs.c
                dfs.c
                Queue.h
                bfs.h
                dfs.h
)