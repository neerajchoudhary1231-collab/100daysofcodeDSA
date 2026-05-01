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

int dequeue(struct Node** front) {
    if (*front == NULL) return -1;
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return data;
}

int main(void) {
    struct Node *front = NULL, *rear = NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    printf("Dequeued: %d\n", dequeue(&front));
    printf("Remaining queue: ");
    for (struct Node* cur = front; cur != NULL; cur = cur->next) {
        printf("%d ", cur->data);
    }
    printf("\n");
    return 0;
}