#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main(void) {
    char s[] = "abca";
    int freq[26] = {0};
    int found = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 2) {
            printf("First repeated: %c\n", s[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("No repeated character\n");
    return 0;
}