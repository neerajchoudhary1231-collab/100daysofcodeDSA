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

struct Node* reverse_list(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    struct Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    printf("Original list: ");
    print_list(head);
    head = reverse_list(head);
    printf("Reversed list: ");
    print_list(head);
    return 0;
}