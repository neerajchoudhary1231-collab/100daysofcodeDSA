#include <stdio.h>

// Check if painting is possible within given time
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

    int low = arr[0], high = 0, ans = 0;

    // Initialize low and high
    for(int i = 0; i < n; i++) {
        if(arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    // Binary Search
    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1; // minimize
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
