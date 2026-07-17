
#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include <stddef.h>
typedef struct Node{
        int data;
        struct Node *left;
        struct Node *right;
}Node;

Node* new_node(int);
void in_order(Node*);
void post_order(Node*);
void pre_order(Node*);

#endif 

