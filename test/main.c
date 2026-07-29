#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// ---------- Adjacency list (same as before) ----------

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// ---------- Simple array-based min-priority queue ----------
// Not a heap: just an unsorted array. insert = O(1) append,
// extractMin = O(n) linear scan. Much less code than a heap,
// but slower asymptotically -- fine for learning / small graphs.

struct PQItem {
    int v;
    int dist;
    bool inQueue;   // lets us "remove" without shifting the array
};

struct PriorityQueue {
    struct PQItem* items;  // indexed directly by vertex number
    int size;               // number of items still inQueue
    int capacity;
};

struct PriorityQueue* createPQ(int capacity) {
    struct PriorityQueue* pq = malloc(sizeof(struct PriorityQueue));
    pq->items = malloc(capacity * sizeof(struct PQItem));
    pq->capacity = capacity;
    pq->size = capacity;
    for (int v = 0; v < capacity; v++) {
        pq->items[v].v = v;
        pq->items[v].dist = INT_MAX;
        pq->items[v].inQueue = true;
    }
    return pq;
}

bool pqIsEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

// Linear scan for the item with the smallest dist among those still queued
int pqExtractMin(struct PriorityQueue* pq) {
    int minDist = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < pq->capacity; v++) {
        if (pq->items[v].inQueue && pq->items[v].dist < minDist) {
            minDist = pq->items[v].dist;
            minIndex = v;
        }
    }

    if (minIndex == -1) return -1; // nothing left reachable

    pq->items[minIndex].inQueue = false;
    pq->size--;
    return minIndex;
}

// Lower a vertex's priority (its distance). O(1) since items[]
// is indexed directly by vertex number -- no searching needed.
void pqDecreaseKey(struct PriorityQueue* pq, int v, int newDist) {
    pq->items[v].dist = newDist;
}

// ---------- Dijkstra using the priority queue ----------

void printArr(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    struct PriorityQueue* pq = createPQ(V);
    pqDecreaseKey(pq, src, 0);

    while (!pqIsEmpty(pq)) {
        int u = pqExtractMin(pq);
        if (u == -1) break; // remaining vertices unreachable

        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (pq->items[v].inQueue && dist[u] != INT_MAX &&
                dist[u] + pCrawl->weight < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                pqDecreaseKey(pq, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(dist, V);

    free(pq->items);
    free(pq);
}

// ---------- Example usage (same graph as before) ----------

int main() {
    int V = 9;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}