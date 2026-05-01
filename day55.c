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

void right_view(struct Node* root) {
    if (!root) return;
    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; ++i) {
            struct Node* node = q[front++];
            if (i == size - 1) printf("%d ", node->data);
            if (node->left) q[rear++] = node->left;
            if (node->right) q[rear++] = node->right;
        }
    }
    printf("\n");
}

int main(void) {
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->right = create_node(5);
    printf("Right view: ");
    right_view(root);
    return 0;
}