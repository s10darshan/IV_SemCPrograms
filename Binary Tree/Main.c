#include "BinaryTree.h"
#include <stdio.h>

int main(){
            Node *root = build_bst();

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