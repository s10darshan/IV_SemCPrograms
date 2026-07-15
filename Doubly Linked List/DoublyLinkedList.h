/* DoublyLinkedList.h */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#define null NULL
typedef struct DNode {
	int data;
	struct DNode *prev;
	struct DNode *next;
} DNode;


DNode* createDNode(const int);
void insertFront(const int);
void insertBack(const int);
void deleteFront();
void deleteBack();
void displayForward();
void displayBackward();

#endif /* DOUBLYLINKEDLIST_H */
