#include <stdio.h>
#include "DoublyLinkedList.h"

int main(){

            insertBack(112);
            insertBack(911);
            insertBack(-988);

            insertFront(1234);
            insertFront(-55);

            displayBackward();
            displayForward();
            
            deleteBack();
            deleteFront();
            
            displayBackward();
            displayForward();

            return 0;
}