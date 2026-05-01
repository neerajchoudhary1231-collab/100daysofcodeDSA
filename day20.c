#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int count_zero_sum_subarrays(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += arr[j];
            if (sum == 0) count++;
        }
    }
    return count;
}

int compare_ints(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void three_sum(int nums[], int n) {
    qsort(nums, n, sizeof(int), compare_ints);
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);
                left++; right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main(void) {
    int arr[] = {1, -1, 2, -2, 3, -3, 0};
    printf("Zero-sum subarrays: %d\n", count_zero_sum_subarrays(arr, 7));
    int nums[] = {-1, 0, 1, 2, -1, -4};
    printf("Three sum combinations:\n");
    three_sum(nums, 6);
    return 0;
}