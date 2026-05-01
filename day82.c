#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int lower_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int upper_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(void) {
    int arr[] = {1, 2, 2, 3, 4};
    printf("Lower: %d Upper: %d\n", lower_bound(arr, 5, 2), upper_bound(arr, 5, 2));
    return 0;
}