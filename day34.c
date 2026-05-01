#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX 100
int queue[MAX];
int front = 0, rear = -1;

int is_empty(void) { return front > rear; }

void enqueue(int value) {
    if (rear < MAX - 1) queue[++rear] = value;
}

int dequeue(void) {
    if (!is_empty()) return queue[front++];
    return -1;
}

void display(void) {
    for (int i = front; i <= rear; ++i) {
        printf("%d", queue[i]);
        if (i < rear) printf(" ");
    }
    printf("\n");
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue: ");
    display();
    dequeue();
    printf("After dequeue: ");
    display();
    return 0;
}