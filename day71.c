#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 7
int table[SIZE];

void init(void) {
    for (int i = 0; i < SIZE; ++i) table[i] = -1;
}

void insert(int key) {
    int h = key % SIZE;
    int i = 0;
    while (i < SIZE) {
        int idx = (h + i * i) % SIZE;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int main(void) {
    init();
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    printf("Hash table: ");
    for (int i = 0; i < SIZE; ++i) printf("%d ", table[i]);
    printf("\n");
    return 0;
}