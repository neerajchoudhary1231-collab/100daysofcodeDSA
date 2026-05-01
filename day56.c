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

int find_index(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; ++i) if (arr[i] == value) return i;
    return -1;
}

struct Node* build_pre_in(int preorder[], int inorder[], int in_start, int in_end, int* pre_index) {
    if (in_start > in_end) return NULL;
    struct Node* node = create_node(preorder[(*pre_index)++]);
    if (in_start == in_end) return node;
    int in_index = find_index(inorder, in_start, in_end, node->data);
    node->left = build_pre_in(preorder, inorder, in_start, in_index - 1, pre_index);
    node->right = build_pre_in(preorder, inorder, in_index + 1, in_end, pre_index);
    return node;
}

void preorder_print(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder_print(root->left);
    preorder_print(root->right);
}

int main(void) {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int pre_index = 0;
    struct Node* root = build_pre_in(preorder, inorder, 0, 4, &pre_index);
    preorder_print(root);
    printf("\n");
    return 0;
}