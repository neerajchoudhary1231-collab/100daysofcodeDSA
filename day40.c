#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void daily_temperatures(int nums[], int n, int output[]) {
    int stack[100];
    int top = -1;
    for (int i = n - 1; i >= 0; --i) {
        while (top != -1 && nums[i] >= nums[stack[top]]) top--;
        output[i] = top == -1 ? 0 : stack[top] - i;
        stack[++top] = i;
    }
}

int main(void) {
    int arr[] = {3, 1, 4, 2};
    heap_sort(arr, 4);
    printf("Sorted: ");
    for (int i = 0; i < 4; ++i) printf("%d ", arr[i]);
    printf("\n");
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int output[8];
    daily_temperatures(temps, 8, output);
    printf("Daily temperatures: ");
    for (int i = 0; i < 8; ++i) printf("%d ", output[i]);
    printf("\n");
    return 0;
}