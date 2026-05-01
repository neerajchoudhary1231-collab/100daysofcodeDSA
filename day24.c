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

int has_cycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main(void) {
    struct Node* head = create_node(1);
    struct Node* second = create_node(2);
    struct Node* third = create_node(3);
    head->next = second;
    second->next = third;
    third->next = second; // cycle
    printf("Has cycle: %s\n", has_cycle(head) ? "yes" : "no");
    return 0;
}