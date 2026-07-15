//
// Created by sdarshan on 7/14/26.
//

#ifndef IV_SEM_SINGLYLINKEDLIST_H
#define IV_SEM_SINGLYLINKEDLIST_H

#define null NULL
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(const int);
void displayList();
void insertAtEnd(const int);
void deleteAtEnd();
void deleteAtBeginning();
void deleteAt(const int);
void insertAtBeginning(const int);
void insertAt(const int, const int);

#endif //IV_SEM_SINGLYLINKEDLIST_H
