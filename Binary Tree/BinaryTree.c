#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

Node* new_node(const int data){
            Node* newNode = malloc(sizeof(Node));
            if (!newNode){
                    fprintf(stderr, "\nCannot create new node.<---\n");
                    return NULL;
            }   

            newNode->data = data;
            newNode->left = newNode->right = NULL;
            return newNode;

}

void in_order(const Node *root){
            if(root == NULL)   return;
            in_order(root->left);
            printf("%d ", root->data);
            in_order(root->right);
}

void post_order(const Node *root ){
            if (root == NULL) return;
            printf("%d ", root->data);
            post_order(root->left);
            post_order(root->right);
}

void pre_order(const Node *root){
            if (root == NULL) return;
            pre_order(root->left);
            pre_order(root->right);
            printf("%d ", root->data);
}