#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infix_to_postfix(char* exp, char* output) {
    char stack[100];
    int top = -1;
    int k = 0;
    for (int i = 0; exp[i] != '\0'; ++i) {
        char c = exp[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            output[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') output[k++] = stack[top--];
            if (top >= 0) top--;
        } else if (is_operator(c)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) output[k++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top >= 0) output[k++] = stack[top--];
    output[k] = '\0';
}

int main(void) {
    char exp[] = "a+b*c-(d/e)";
    char output[100];
    infix_to_postfix(exp, output);
    printf("Postfix: %s\n", output);
    return 0;
}