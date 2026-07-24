#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int adj[SIZE][SIZE], visited[SIZE];
int queue[SIZE], front = -1, rear = -1;

void enqueue(const int value){
        if(rear == SIZE - 1){
                fprintf(stderr, "\n-->Queue full.<---\n");
                return;
        }

        if (front == -1)  front = 0;
        queue[++rear] = value;
}

int dequeue(){
        if (front == -1 || front > rear){
                fprintf(stderr, "\n--->Queue empty<---\n");
                return -1;
        }

        return queue[front++];
}