#include <stdio.h>
#include "Queue.h"
#include "bfs.h"
#include "dfs.h"
#define SIZE 10


int main(){
        int vertices_count, edges_count, u, v, start;
        printf("Enter no. of vertices:\n> ");
        scanf("%d", &vertices_count);
  
        printf("Enter no. of edges:\n ");
        scanf("%d", &edges_count);

        /* Initializing Adjency matrix */
        for (int i = 0; i < edges_count; i++){
                printf("Enter edge(u,v):\n ");
                scanf("%d%d", &u, &v);
                adj[u][v] = adj[v][u] = 1;
        }

        printf("Enter starting vertex for BFS & DFS:\n> ");
        scanf("%d", &start);

        bfs(start, vertices_count);

        printf("\n");
        dfs(start, vertices_count);
        printf("\n");

        return 0;
}