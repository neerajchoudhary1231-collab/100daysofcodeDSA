#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) stack[++top] = value;
}

int pop(void) {
    if (top >= 0) return stack[top--];
    return -1;
}

int main(void) {
    int n = 5;
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < n; ++i) push(values[i]);
    int m = 2;
    for (int i = 0; i < m; ++i) pop();
    printf("Stack after popping %d elements: ", m);
    for (int i = top; i >= 0; --i) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    return 0;
}