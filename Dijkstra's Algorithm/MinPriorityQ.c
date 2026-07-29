#include <stdlib.h>
#include <stdio.h>
#include "MinPriorityQ.h"

MinPriorityQ* create_queue(const int vertex_count){
            MinPriorityQ* new_queue = malloc(sizeof(MinPriorityQ));
            if( new_queue == NULL){
                    fprintf(stderr, "\n--->Unable to create new queue.<---\n");
                    return NULL;
            }
             /* every vertex is initially in the queue */
            new_queue->capacity = new_queue->size = vertex_count;

            /* queue conatins array of QItems */
            new_queue->items = malloc(vertex_count * sizeof(QItems));

            /*  Initially, all the items are in the queue so: boolInQueue = true
                the vertex themselves act as the index for this queue

            */

            for (int v = 0; v < vertex_count; v++){
                    new_queue->items[v].vertex = v;
                    new_queue->items[v].bestDistance = __INT_MAX__;
                    new_queue->items[v].boolInQueue = true;
            }

            return new_queue;
}

bool is_Qempty(MinPriorityQ* q){ return q->size == 0; }

int get_optimal_vertex_distance(MinPriorityQ* q){
                int min_distance = __INT_MAX__;
                int minIndex = -1; /* -1 indicates unreachable vertex */

                for(int v = 0; v < q->capacity; v++){
                        if( q->items[v].boolInQueue &&
                                q->items[v].bestDistance < min_distance){
                                        min_distance = q->items[v].bestDistance;
                                        minIndex = v;
                        }
                }

                if (minIndex == -1) return -1;
                q->items[minIndex].boolInQueue = false;
                q->size--;
                return minIndex;
}

void new_best_distance(MinPriorityQ* q, const int vertex, 
                const int new_distance){
                    q->items[vertex].bestDistance = new_distance;
}