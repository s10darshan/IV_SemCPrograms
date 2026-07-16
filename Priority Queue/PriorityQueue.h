
#ifndef PRIORITY_QUEUE_PRIORITYQUEUE_H
#define PRIORITY_QUEUE_PRIORITYQUEUE_H

#define null NULL
#include <stddef.h>

typedef struct Node {
	int data;
	int priority;
	struct Node* next;
}Node;


Node* newNode(int data, int priority);
void enqueue(int data, int priority);
void dequeue(void);
void displayQueue(void);

#endif //PRIORITY_QUEUE_PRIORITYQUEUE_H
