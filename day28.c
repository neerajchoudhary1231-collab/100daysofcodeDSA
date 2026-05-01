#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_circular(struct Node* head, int n) {
    if (!head) return;
    struct Node* current = head;
    for (int i = 0; i < n; ++i) {
        printf("%d", current->data);
        if (i < n - 1) printf(" ");
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    int n = 4;
    int values[] = {10, 20, 30, 40};
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        struct Node* node = create_node(values[i]);
        if (!head) head = tail = node;
        else tail->next = node, tail = node;
    }
    tail->next = head;
    print_circular(head, n);
    return 0;
}