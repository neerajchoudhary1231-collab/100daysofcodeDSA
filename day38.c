#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX 100
int deque_arr[MAX];
int front = -1, rear = -1;

int is_empty(void) { return front == -1; }
int is_full(void) { return (front == 0 && rear == MAX - 1) || (front == rear + 1); }

void push_back(int x) {
    if (is_full()) return;
    if (is_empty()) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    deque_arr[rear] = x;
}

void push_front(int x) {
    if (is_full()) return;
    if (is_empty()) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    deque_arr[front] = x;
}

int main(void) {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    printf("Deque contents: ");
    int i = front;
    while (1) {
        printf("%d", deque_arr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
        printf(" ");
    }
    printf("\n");
    return 0;
}