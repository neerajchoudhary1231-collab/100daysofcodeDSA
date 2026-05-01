#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* lca_bst(struct Node* root, int n1, int n2) {
    while (root) {
        if (root->data > n1 && root->data > n2) root = root->left;
        else if (root->data < n1 && root->data < n2) root = root->right;
        else return root;
    }
    return NULL;
}

int main(void) {
    struct Node* root = create_node(6);
    root->left = create_node(2);
    root->right = create_node(8);
    root->left->left = create_node(0);
    root->left->right = create_node(4);
    struct Node* ans = lca_bst(root, 0, 4);
    if (ans) printf("LCA: %d\n", ans->data);
    return 0;
}