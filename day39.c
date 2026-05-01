#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX 1000
int heap[MAX];
int heap_size = 0;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

void heapify_down(int i) {
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap_size && heap[left] < heap[smallest]) smallest = left;
        if (right < heap_size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int x) {
    heap[heap_size++] = x;
    heapify_up(heap_size - 1);
}

int main(void) {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    printf("Min-heap contents: ");
    for (int i = 0; i < heap_size; ++i) printf("%d ", heap[i]);
    printf("\n");
    return 0;
}