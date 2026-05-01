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

struct Pair { struct Node* node; int hd; };

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void vertical_order(struct Node* root) {
    if (!root) return;
    struct Pair queue[1000];
    int front = 0, rear = 0;
    int hd[1000];
    int val[1000];
    int count = 0;
    queue[rear++] = (struct Pair){root, 0};
    while (front < rear) {
        struct Pair cur = queue[front++];
        hd[count] = cur.hd;
        val[count++] = cur.node->data;
        if (cur.node->left) queue[rear++] = (struct Pair){cur.node->left, cur.hd - 1};
        if (cur.node->right) queue[rear++] = (struct Pair){cur.node->right, cur.hd + 1};
    }
    for (int x = -100; x <= 100; ++x) {
        int printed = 0;
        for (int i = 0; i < count; ++i) {
            if (hd[i] == x) {
                if (printed) printf(" ");
                printf("%d", val[i]);
                printed = 1;
            }
        }
        if (printed) printf("\n");
    }
}

int main(void) {
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->right->right = create_node(5);
    vertical_order(root);
    return 0;
}