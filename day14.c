#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void rotate_array(int nums[], int n, int k) {
    k %= n;
    if (k < 0) k += n;
    int temp[100];
    for (int i = 0; i < n; ++i) temp[i] = nums[(i - k + n) % n];
    for (int i = 0; i < n; ++i) nums[i] = temp[i];
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    rotate_array(nums, n, 3);
    printf("Rotated array: ");
    for (int i = 0; i < n; ++i) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}