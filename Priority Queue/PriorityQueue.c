#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

Node* front = null;
Node* newNode(const int data, const int priority) {
			Node* new_node = malloc(sizeof(Node));
			new_node->data = data;
			new_node->priority = priority;
			new_node->next = null;

			return new_node;
}

void enqueue(const int data, const int priority) {

			Node* new_node = newNode(data, priority);
			if (front == null || priority < front->priority) {
				new_node->next = front;
				front = new_node;
			} else {
				Node* temp = front;
				while (temp->next && temp->next->priority <= priority)
					temp = temp->next;
				new_node->next = temp->next;
				temp->next = new_node;
			}
}

void dequeue() {

			if (front == null) {
				printf("Queue is empty.\n");
				return;
			}
			Node* temp = front;
			printf("Dequeued: %d (priority %d)\n", temp->data, temp->priority);
			front = front->next;
			free(temp);
}

void displayQueue() {

			Node* temp = front;
			printf("Priority Queue: ");
			while (temp) {
				printf("[%d|P:%d] -> ", temp->data, temp->priority);
				temp = temp->next;
			}
			printf("NULL\n");
}