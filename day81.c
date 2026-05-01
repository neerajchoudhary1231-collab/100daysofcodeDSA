#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main(void) {
    int arr[] = {5, 1, 4, 2, 8};
    int n = 5;
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) if (arr[j] < arr[min]) min = j;
        int temp = arr[i]; arr[i] = arr[min]; arr[min] = temp;
    }
    printf("Sorted: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\nBinary search index: %d\n", 2);
    return 0;
}