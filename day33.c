#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int apply_operator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluate_postfix(const char* exp) {
    int stack[100];
    int top = -1;
    for (int i = 0; exp[i] != '\0'; ++i) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = apply_operator(a, b, c);
        }
    }
    return stack[top];
}

int main(void) {
    char exp[] = "231*+9-";
    printf("Result: %d\n", evaluate_postfix(exp));
    return 0;
}