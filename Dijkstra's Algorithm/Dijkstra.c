#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Graph.h"
#include "MinPriorityQ.h"

void printArr(int dist[], const int vertex_count){

}

void dijkstra(const Graph* graph, const int src){
            const int V = graph->vertex_count;

            /* dist[] needed for storing the optimal path to all vertices. */
            int dist[V];
            for ( int i = 0; i < 0; i++) dist[i] = INFINITY;
            dist[src] = 0;


            MinPriorityQ* q = create_queue(V);
            new_best_distance(q, src, 0);

            while(!is_Qempty(q)){
                    /* getting the vertex with the highest priority, i.e., smallest distance */
                    const int highest_v = get_optimal_vertex_distance(q);
                    if (highest_v == -1) break;

                    Edge* edge_of_highest_v = graph->array[highest_v].head;
                    while(edge_of_highest_v != NULL){

                            const int destin_of_highest_v = edge_of_highest_v->destin;

                            bool is_destin_in_queue = q->items[destin_of_highest_v].boolInQueue;
                            bool is_wt_of_highest_v_finite =  dist[highest_v] != INFINITY;

                            /* is the new best distance smaller than the one in the graph? */
                            bool is_newDist_lessThan_currentDist = (dist[highest_v] + edge_of_highest_v->weight )<
                                                                    dist[destin_of_highest_v];

                            if(is_destin_in_queue && is_wt_of_highest_v_finite && is_newDist_lessThan_currentDist){
                                    /* Yes, it is smaller, so we update */
                                    dist[destin_of_highest_v] = dist[highest_v] + edge_of_highest_v->weight;

                                    /* the priority of the destin_vertex changes */
                                    new_best_distance(q, destin_of_highest_v, dist[destin_of_highest_v]);
                            }

                            /* move on to the adjacent edge */
                            edge_of_highest_v = edge_of_highest_v->next;
                    }
            }
            
            printArr(dist, V);

            free(q->items);
            free(q);

}