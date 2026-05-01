#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int find_peak(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1]) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main(void) {
    int arr[] = {1, 3, 2, 1};
    printf("Peak index: %d\n", find_peak(arr, 4));
    return 0;
}