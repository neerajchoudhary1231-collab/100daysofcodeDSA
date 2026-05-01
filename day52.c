#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* left = lca(root->left, n1, n2);
    struct Node* right = lca(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

int main(void) {
    struct Node* root = create_node(3);
    root->left = create_node(5);
    root->right = create_node(1);
    root->left->left = create_node(6);
    root->left->right = create_node(2);
    struct Node* ans = lca(root, 6, 2);
    if (ans) printf("LCA: %d\n", ans->data);
    return 0;
}