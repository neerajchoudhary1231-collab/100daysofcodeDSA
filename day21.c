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

void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    int n = 5;
    int values[] = {1, 2, 3, 4, 5};
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        struct Node* node = create_node(values[i]);
        if (head == NULL) head = tail = node;
        else tail->next = node, tail = node;
    }
    printf("Linked list: ");
    print_list(head);
    return 0;
}