#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <limits.h>

typedef struct {
    int arr[100];
    int front;
    int rear;
    int size;
} CircularQueue;

void init(CircularQueue* q, int n) {
    q->front = 0;
    q->rear = -1;
    q->size = n;
}

int is_full(CircularQueue* q) { return (q->rear + 1) % q->size == q->front && q->rear != -1; }

int is_empty(CircularQueue* q) { return q->rear == -1; }

void enqueue(CircularQueue* q, int value) {
    if (is_full(q)) return;
    if (is_empty(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
}

int main(void) {
    CircularQueue q;
    init(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Circular queue values: %d %d %d\n", q.arr[q.front], q.arr[(q.front+1)%q.size], q.arr[(q.front+2)%q.size]);
    return 0;
}