#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void append(struct Node** head, int data) {
    struct Node* node = create_node(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* tail = *head;
    while (tail->next != NULL) tail = tail->next;
    tail->next = node;
    node->prev = tail;
}

void print_forward(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    struct Node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("Doubly linked list: ");
    print_forward(head);
    return 0;
}