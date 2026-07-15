#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

DNode* head = null;
DNode* createDNode(const int data){
            DNode* new_node = malloc(sizeof(DNode));
            new_node->data = data;
            new_node->next = null;
            new_node->prev = null;
            return new_node;
}

void insertBack(const int data) {
            DNode* new_node = createDNode(data);
            if (head == null) {
                    head = new_node;
                    return;
            }

            DNode* temp = head;
            while (temp->next)
                    temp = temp->next;

            temp->next = new_node;
            new_node->prev = temp;
    
}

void insertFront(const int data){
            DNode* new_node = createDNode(data);

            if(head == null) {
                    head = new_node;
                    return;
            }

            new_node->next = head;
            head->prev = new_node;
            head = new_node;
}

void deleteBack(){
            DNode* temp = head;
            if (!temp) return;
            if (!temp->next) { /* only one node */
                    free(temp);
                    head = null;
                    return;
            }

            while (temp->next && temp->next->next)
                    temp = temp->next;

            /* temp now points to second last node */
            free(temp->next);
            temp->next = null;
}

void deleteFront(){
            DNode* temp = head;

            /* if no node exists */
            if(!temp) return;

            /* If one node exists */
            if(!temp->next){
                    free(head);
                    head = null;
                    return;
            }

            /* If multiple node exists */
            DNode* second_node = head->next;
            free(head);
            head = second_node;
            second_node->prev = null;
                       

}

void displayForward() {
            DNode* temp = head;
            printf("Forward: ");
            while (temp) {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
            }
            printf("NULL\n");
}

void displayBackward() {
            DNode* temp = head;
            if (!temp) return;

            while (temp->next)
                temp = temp->next;

            printf("Backward: ");
            while (temp) {
                printf("%d <- ", temp->data);
                temp = temp->prev;
            }
            printf("NULL\n");
}