#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 10

extern int adj[SIZE][SIZE], visited[SIZE];
extern int queue[SIZE];
extern int front , rear;
void enqueue(int value);
int dequeue(void);

#endif 