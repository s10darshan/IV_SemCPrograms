//
// Created by sdarshan on 7/14/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

Node* head = NULL;
Node* newNode(const int data) {
            Node* newNode = malloc(sizeof(Node));

            if (newNode == NULL) {
                    printf("Memory allocation failed\n");
                    exit(-1);
            }
            newNode->data = data;
            newNode->next = NULL;

            return newNode;
}

void insertAtBeginning(const int data) {
	Node* new_node = newNode(data);
	if (head == NULL) {
		head = new_node;
		return;
	}

	new_node->next = head;
	head = new_node;
}

void insertAtEnd(const int data) {
           Node* new_node = newNode(data);

            if (head == NULL) {
                head = new_node;
                return;
            }

            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = new_node;

}
void insertAt(const int pos, const int data) {

			if (pos < 0) {
					fprintf(stderr, "\n--->Invalid position.<---");
					return;
			}

			Node* new_node = newNode(data);
			Node* temp = head;

			// if the pos -> first node
			if (pos == 0) {
					new_node->next = head;
					head = new_node;
					return;
			}

			// traverse till list[pos - 1]
			for (int i = 0; i < pos-1; i++)
						temp = temp->next;

			//if the pos -> after the last node
			if (!temp->next) {
					temp->next = new_node;
					return;
			}

			// insert the node
			new_node->next = temp->next;
			temp->next = new_node;

}

void deleteAtBeginning(){

            if (head == NULL) {
	                fprintf(stderr,"List is empty\n");
	                return;
            }

            Node* temp = head;
            head = head->next;
            free(temp);
}
void deleteAtEnd() {

			if (head == NULL) {
					fprintf(stderr,"\n--->List is empty.<---\n");
					return;
			}

			Node* temp = head;

			// traversing till the second last node
			while (temp->next->next)
					temp = temp->next;

			free(temp->next);
			temp->next = nullptr;
}
void deleteAt(const int pos) {
			if (pos < 0) {
					fprintf(stderr, "\n--->Invalid position.<---");
					return;
			}

			Node* temp = head;

			if (pos == 0) {
					head = head->next;
					free(temp);
					return;
			}

			// traverse till list[pos - 1]
			for (int i = 0; i < pos-1; i++)
						temp = temp->next;

			// If pos -> after last node
			if (!temp->next) {
					fprintf(stderr, "\n--->Position out of bounds.<---");
					return;
			}

			Node* afterPosNode = temp->next->next;
			free(temp->next);
			temp->next = afterPosNode;
}

void displayList() {
            const Node* temp = head;
            printf("Singly Linked List: ");
            while (temp) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
}
