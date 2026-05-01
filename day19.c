#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int closest_to_zero(int arr[], int n) {
    int best = arr[0];
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i]) < abs(best) || (abs(arr[i]) == abs(best) && arr[i] > best)) best = arr[i];
    }
    return best;
}

int max_subarray_circular(int nums[], int n) {
    int max_ending = nums[0], max_so_far = nums[0];
    int min_ending = nums[0], min_so_far = nums[0];
    int total = nums[0];
    for (int i = 1; i < n; ++i) {
        max_ending = nums[i] > max_ending + nums[i] ? nums[i] : max_ending + nums[i];
        max_so_far = max_so_far > max_ending ? max_so_far : max_ending;
        min_ending = nums[i] < min_ending + nums[i] ? nums[i] : min_ending + nums[i];
        min_so_far = min_so_far < min_ending ? min_so_far : min_ending;
        total += nums[i];
    }
    if (min_so_far == total) return max_so_far;
    int circular = total - min_so_far;
    return circular > max_so_far ? circular : max_so_far;
}

int main(void) {
    int arr[] = {-8, 4, 5, -10, 3};
    printf("Closest to zero: %d\n", closest_to_zero(arr, 5));
    int nums[] = {5, -3, 5};
    printf("Max circular subarray: %d\n", max_subarray_circular(nums, 3));
    return 0;
}