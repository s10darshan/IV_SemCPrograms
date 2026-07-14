//
// Created by sdarshan on 7/14/26.
//

#ifndef IV_SEM_SINGLYLINKEDLIST_H
#define IV_SEM_SINGLYLINKEDLIST_H
struct Node {
    int data;
    struct Node* next;
};

void displayList();
void insertAtEnd(const int value);
void deleteAtEnd();
void deleteAtBeginning();
void deleteAtCurrent();
void insertAtBeginning(const int value);
void insertAtCurrent(const int value);

#endif //IV_SEM_SINGLYLINKEDLIST_H
