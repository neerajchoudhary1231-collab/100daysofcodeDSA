#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void product_except_self(int nums[], int n, int output[]) {
    int left[100];
    left[0] = 1;
    for (int i = 1; i < n; ++i) left[i] = left[i - 1] * nums[i - 1];
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        output[i] = left[i] * right;
        right *= nums[i];
    }
}

int main(void) {
    int nums[] = {1, 2, 3, 4};
    int output[4];
    product_except_self(nums, 4, output);
    printf("Product except self: ");
    for (int i = 0; i < 4; ++i) printf("%d ", output[i]);
    printf("\n");
    return 0;
}