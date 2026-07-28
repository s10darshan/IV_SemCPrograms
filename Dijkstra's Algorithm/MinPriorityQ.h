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

MinPriorityQ* create_queue(int);
bool is_Qempty(MinPriorityQ*);
int get_optimal_vertex(MinPriorityQ*);

#endif