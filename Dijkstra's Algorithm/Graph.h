#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge Edge;
/* Linked List that stores adjacent edges of the vertex */
struct Edge{
        int destination, weight;
        Edge* next;
};

/* elements of array: contains the head pointer to above linked list */
typedef struct EdgeList {
        Edge* head;
}EdgeList;

typedef struct Graph{
        int vertex_count;     /* no. of vertices */
        EdgeList* array;     /* the array of edges connected to/from the edges */
}Graph;

Edge* newEdge(int,int);
void createGraph(int);
void addEdge();

#endif