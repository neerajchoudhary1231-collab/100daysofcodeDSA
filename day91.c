#include <stdio.h>

// Check if we can paint with given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxTime)
            return 0;

        if(sum + arr[i] <= maxTime) {
            sum += arr[i];
        } else {
            painters++;
            sum = arr[i];

            if(painters > k)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0, high = 0;

    // Set search space
    for(int i = 0; i < n; i++) {
        if(arr[i] > low)
            low = arr[i];  // max element
        high += arr[i];   // total sum
    }

    int ans = high;

    // Binary Search
    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;  // increase
        }
    }

    printf("%d", ans);

    return 0;
}
