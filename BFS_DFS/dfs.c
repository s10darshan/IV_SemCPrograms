#include <stdio.h>
#include "Queue.h"

static void dfs_util(const int node, const int vertices_count){
        visited[node] = 1;
        printf("%d ", node);

        for(int i = 0; i < vertices_count; i++)
                if(adj[node][i] && !visited[i])
                        dfs_util(i, vertices_count);
}

void dfs(const int node, const int vertices_count){
        for (int i = 0; i < vertices_count; i++)
                visited[i] = 0;

        printf("DFS Traversal: ");
        dfs_util(node, vertices_count);
        printf("\n");
}