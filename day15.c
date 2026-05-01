#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void find_max_min(int arr[], int n, int *maxv, int *minv) {
    *maxv = INT_MIN;
    *minv = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > *maxv) *maxv = arr[i];
        if (arr[i] < *minv) *minv = arr[i];
    }
}

int max_subarray(int nums[], int n) {
    int best = nums[0];
    int cur = nums[0];
    for (int i = 1; i < n; ++i) {
        cur = nums[i] > cur + nums[i] ? nums[i] : cur + nums[i];
        if (cur > best) best = cur;
    }
    return best;
}

int main(void) {
    int arr[] = {-2, 0, 1, -3};
    int maxv, minv;
    find_max_min(arr, 4, &maxv, &minv);
    printf("Max: %d, Min: %d\n", maxv, minv);
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("Max subarray: %d\n", max_subarray(nums, 9));
    return 0;
}