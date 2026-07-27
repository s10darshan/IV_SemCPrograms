#ifndef GRAPH_H
#define GRAPH_H

typedef struct AdjEdge AdjEdge;
/* Linked List that stores adjacent edges of the vertex */
struct AdjEdge{
        int destination, weight;
        AdjEdge* next;
};

/* elements of array: contains the head pointer to above linked list */
typedef struct AdjEdgeList {
        AdjEdge* head;
}AdjEdgeList;

typedef struct Graph{
        int vertex;     /* the actual vertex */
        AdjEdgeList* array;     /* the array of edges connected to/from the edges */
};

AdjEdge* newEdge(int,int);
void createGraph(int);
void addEdge();

#endif