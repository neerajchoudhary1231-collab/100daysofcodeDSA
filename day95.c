#include <stdio.h>
#include <stdlib.h>

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for(int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Step 1: Create buckets
    float *buckets[n];
    int count[n];

    for(int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        count[i] = 0;
    }

    // Step 2: Distribute elements into buckets
    for(int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        buckets[index][count[index]++] = arr[i];
    }

    // Step 3: Sort each bucket
    for(int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Step 4: Concatenate buckets
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Output
    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    // Free memory
    for(int i = 0; i < n; i++) {
        free(buckets[i]);
    }

    return 0;
}
