#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void reverse_string(char s[]) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}

int main(void) {
    char s[] = "hello";
    reverse_string(s);
    printf("Reversed string: %s\n", s);
    return 0;
}