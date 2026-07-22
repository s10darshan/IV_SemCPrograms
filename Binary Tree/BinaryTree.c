#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BinaryTree.h"

int height_of_tree(const Node* root) {
			if (root == NULL) return 0;

			int left = height_of_tree(root->left);
			int right = height_of_tree(root->right);

                        return 1 + (left > right ? left : right);
}

int node_count(const Node *root) {
			if (root == NULL)	return 0;

			return 1 + node_count(root->left) + node_count(root->right);
}

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

static Node* bst_insert(Node *root, const int data){
            if (root == NULL) return new_node(data);

            if (data < root->data) {
                    root->left = bst_insert(root->left, data);
            } else {
                    root->right = bst_insert(root->right, data);
            }

            return root;
}

Node* build_bst(void){
            Node *root = NULL;
            int data;

            printf("Enter BST values (-1 to stop):\n");
            while(1){
                    printf("Enter data:\n> ");
                    if (scanf("%d", &data) != 1) break;
                    if (data == -1) break;

                    root = bst_insert(root, data);
            }

            return root;
}