
#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include <stddef.h>
typedef struct Node{
        int data;
        struct Node *left;
        struct Node *right;
}Node;

Node* new_node(int);
Node* build_bst(void);
void in_order(const Node*);
void post_order(const Node*);
void pre_order(const Node*);
int node_count(const Node*);
int height_of_tree(const Node*);

#endif 

