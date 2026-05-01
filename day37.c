#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX 100

typedef struct {
    int value;
    int priority;
} PQNode;

PQNode pq[MAX];
int size = 0;

void enqueue(int value, int priority) {
    int i = size - 1;
    while (i >= 0 && pq[i].priority < priority) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1].value = value;
    pq[i + 1].priority = priority;
    size++;
}

int main(void) {
    enqueue(10, 2);
    enqueue(30, 4);
    enqueue(20, 3);
    printf("Priority queue order:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d(%d) ", pq[i].value, pq[i].priority);
    }
    printf("\n");
    return 0;
}