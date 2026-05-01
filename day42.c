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

void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* node = create_node(value);
    if (*rear == NULL) {
        *front = *rear = node;
        return;
    }
    (*rear)->next = node;
    *rear = node;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) return -1;
    struct Node* temp = *front;
    int value = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return value;
}

void push(int stack[], int *top, int value) {
    stack[++(*top)] = value;
}

int pop(int stack[], int *top) {
    return (*top >= 0) ? stack[(*top)--] : -1;
}

void reverse_queue(struct Node** front, struct Node** rear) {
    int stack[100];
    int top = -1;
    while (*front != NULL) {
        push(stack, &top, dequeue(front, rear));
    }
    while (top >= 0) {
        enqueue(front, rear, pop(stack, &top));
    }
}

int main(void) {
    struct Node *front = NULL, *rear = NULL;
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    reverse_queue(&front, &rear);
    printf("Reversed queue: ");
    for (struct Node* cur = front; cur != NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
    return 0;
}