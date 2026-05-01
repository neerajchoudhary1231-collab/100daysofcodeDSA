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

struct Node* rotate_right(struct Node* head, int k) {
    if (!head || k == 0) return head;
    int length = 1;
    struct Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        ++length;
    }
    k %= length;
    if (k == 0) return head;
    tail->next = head;
    int steps = length - k;
    struct Node* new_tail = head;
    for (int i = 1; i < steps; ++i) new_tail = new_tail->next;
    struct Node* new_head = new_tail->next;
    new_tail->next = NULL;
    return new_head;
}

void print_list(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    struct Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    printf("Original list: "); print_list(head);
    head = rotate_right(head, 2);
    printf("Rotated list: "); print_list(head);
    return 0;
}