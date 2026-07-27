#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

void createGraph(const int vCount){
            Graph* new_graph = (Graph*) malloc(sizeof(Graph));
            if(new_graph == NULL){
                    fprintf(stderr, "\n--->Unable to create new graph.<---\n");
                    return;
            }
            new_graph->vertex_count = vCount;
            new_graph->array = (EdgeList*) malloc(sizeof(EdgeList));
            for (int i = 0; i < vCount; i++)
                        new_graph->array[i].head = NULL;
            return new_graph;
}


