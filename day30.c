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

void display(void) {
    for (int i = top; i >= 0; --i) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

int main(void) {
    push(10);
    push(20);
    push(30);
    printf("Stack content: ");
    display();
    printf("Popped: %d\n", pop());
    printf("Stack after pop: ");
    display();
    return 0;
}