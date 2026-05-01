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

int is_min_heap(struct Node* root) {
    if (!root) return 1;
    if (root->left && root->data > root->left->data) return 0;
    if (root->right && root->data > root->right->data) return 0;
    return is_min_heap(root->left) && is_min_heap(root->right);
}

int main(void) {
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    printf("Is min heap: %s\n", is_min_heap(root) ? "yes" : "no");
    return 0;
}