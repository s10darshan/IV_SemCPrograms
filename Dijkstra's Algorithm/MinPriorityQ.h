#ifndef MINPRIORITYQ_H
#define MINPRIORITYQ_H

/* Represents the element of queue, i.e., vertex and its best known distance */
typedef struct MinQItems{
        bool boolInQueue;
        int vertex, bestDistance;
}QItems;

typedef struct MinPriorityQ { 
        int size; /* count of items still in queue */
        int capacity; /* vertex count in the queue */
        QItems* items;
}MinPriorityQ; 

MinPriorityQ* create_queue(int); /* func() paramater: vertex_count */
bool is_Qempty(MinPriorityQ*);
int get_optimal_vertex_distance(MinPriorityQ*);

 /* func parameters: queue, the vertex, new best_distance */
void new_best_distance(MinPriorityQ*, int, int); 
#endif