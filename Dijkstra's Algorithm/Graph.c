#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

Edge* newEdge(const int destination, const int weight){
        Edge* new_edge = (Edge*)malloc(sizeof(Edge*));
        if( new_edge == NULL){
                fprintf(stderr, "\n--->Unable to create new edge.<---\n");
                return NULL;
        }
        new_edge->destin = destination;
        new_edge->weight = weight;
        new_edge->next = NULL;

        return new_edge;

}

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

void addEdge(Graph* graph, const int src_vertex, 
                const int destin_vertex, const int weight){

        Edge* new_edge = newEdge(src_vertex, weight);
        if(new_edge == NULL){
                fprintf(stderr, "\n--->Unable to add a enw edge.<---\n");
                return;
        }
        /* adding edge to the soruce vertex */
        new_edge->next = graph->array[src_vertex].head;
        graph->array[src_vertex].head = new_edge;
        
        /*      adding the same edge to the destination vertex
                becuase an edge connects two vertices
        */
        new_edge = newEdge(destin_vertex, weight);
        new_edge->next = graph->array[destin_vertex].head;
        graph->array[destin_vertex].head = new_edge;
        
}


