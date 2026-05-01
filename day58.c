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

int is_min_heap(struct Node* root) {
    if (!root) return 1;
    if (root->left && root->data > root->left->data) return 0;
    if (root->right && root->data > root->right->data) return 0;
    return is_min_heap(root->left) && is_min_heap(root->right);
}

int main(void) {
    struct Node root = {1, NULL, NULL};
    struct Node left = {2, NULL, NULL};
    struct Node right = {3, NULL, NULL};
    root.left = &left;
    root.right = &right;
    printf("Min-heap valid: %s\n", is_min_heap(&root) ? "yes" : "no");
    return 0;
}