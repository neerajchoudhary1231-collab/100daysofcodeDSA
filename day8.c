#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int is_palindrome(const char s[]) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) left++;
        while (left < right && !isalnum((unsigned char)s[right])) right--;
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) return 0;
        left++; right--;
    }
    return 1;
}

int intersection(int nums1[], int n1, int nums2[], int n2, int out[]) {
    int count = 0;
    for (int i = 0; i < n1; ++i) {
        int val = nums1[i];
        int found = 0;
        for (int j = 0; j < count; ++j) if (out[j] == val) { found = 1; break; }
        if (found) continue;
        for (int j = 0; j < n2; ++j) if (nums2[j] == val) { out[count++] = val; break; }
    }
    return count;
}

int main(void) {
    printf("Is palindrome: %s\n", is_palindrome("A man, a plan, a canal: Panama") ? "true" : "false");
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int out[10];
    int count = intersection(nums1, 4, nums2, 2, out);
    printf("Intersection: ");
    for (int i = 0; i < count; ++i) printf("%d ", out[i]);
    printf("\n");
    return 0;
}