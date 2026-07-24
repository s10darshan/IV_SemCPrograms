#include <stdio.h>
#include "Queue.h"

void bfs(const int start, const int vertices_count){
        for (int i = 0; i < vertices_count; i++)
                visited[i] = 0;

        front = rear = -1;
        enqueue(start);
        visited[start] = 1;
        printf("BFS Traversal: ");

        while(front <= rear){
                int node = dequeue();
                printf("%d ", node);
                for(int i = 0; i < vertices_count; i++){
                        if(adj[node][i] && !visited[i]){
                                enqueue(i);
                                visited[i] = 1;
                        }
                }
        }

        printf("\n");
   
}