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

struct Node* build_post_in(int postorder[], int inorder[], int in_start, int in_end, int* post_index) {
    if (in_start > in_end) return NULL;
    struct Node* node = create_node(postorder[(*post_index)--]);
    if (in_start == in_end) return node;
    int in_index = find_index(inorder, in_start, in_end, node->data);
    node->right = build_post_in(postorder, inorder, in_index + 1, in_end, post_index);
    node->left = build_post_in(postorder, inorder, in_start, in_index - 1, post_index);
    return node;
}

void preorder_print(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder_print(root->left);
    preorder_print(root->right);
}

int main(void) {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int post_index = 4;
    struct Node* root = build_post_in(postorder, inorder, 0, 4, &post_index);
    preorder_print(root);
    printf("\n");
    return 0;
}