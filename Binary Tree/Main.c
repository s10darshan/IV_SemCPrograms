#include "BinaryTree.h"
#include <stdio.h>

int main(){
            Node *root = new_node(1);
            root->left = new_node(2);
            root->right = new_node(3);
            root->left->left = new_node(4);
            root->left->right = new_node(5);

            printf("\nIn-order traversal: ");
            in_order(root);
            
            printf("\nPre-order traversal: ");
            pre_order(root);

            printf("\nPost-order traversal: ");
            post_order(root);

            printf("\nTotal number of nodes: %d", node_count(root));

			printf("\nHeight of tree: %d", height_of_tree(root));

            printf("\n");
            return 0;
}