//
// Created by sdarshan on 7/14/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

typedef struct Node Node;
Node* head = NULL;
void insertAtEnd(const int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
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
