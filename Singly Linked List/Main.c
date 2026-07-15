#include <signal.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

int main() {
        insertAtEnd(10);
        insertAtEnd(20);
        insertAtEnd(-54);
        insertAtEnd(0);
        insertAtEnd(-1204);
        printf("InsertAtEnd: ");
        displayList();

        insertAtBeginning(7223);
        printf("InsertAtBeginning: ");
        displayList();

        insertAt(3,-92);
        printf("InsertAt(3): ");
        displayList();

        deleteAtBeginning();
        printf("DeleteAtBeginning(): ");
        displayList();

        deleteAtEnd();
        printf("DeleteAtEnd(): ");
        displayList();

        deleteAt(2);
        printf("DeleteAt(2): ");
        displayList();


        return 0;
}