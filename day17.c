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

int kadane(int arr[], int n) {
    int best = arr[0];
    int current = arr[0];
    for (int i = 1; i < n; ++i) {
        current = arr[i] > current + arr[i] ? arr[i] : current + arr[i];
        if (current > best) best = current;
    }
    return best;
}

int max_subarray_circular(int nums[], int n) {
    int max_k = kadane(nums, n);
    int total = 0;
    int min_ending = nums[0], min_so_far = nums[0];
    for (int i = 0; i < n; ++i) {
        total += nums[i];
        if (i > 0) min_ending = nums[i] < min_ending + nums[i] ? nums[i] : min_ending + nums[i];
        if (min_ending < min_so_far) min_so_far = min_ending;
    }
    if (min_so_far == total) return max_k;
    return total - min_so_far > max_k ? total - min_so_far : max_k;
}

int main(void) {
    int arr[] = {-2, 1, -3, 4};
    printf("Closest to zero: %d\n", closest_to_zero(arr, 4));
    int nums[] = {5,-3,5};
    printf("Max circular subarray: %d\n", max_subarray_circular(nums, 3));
    return 0;
}