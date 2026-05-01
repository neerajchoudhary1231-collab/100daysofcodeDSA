#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages)
            return 0; // single book exceeds limit

        if(sum + arr[i] <= maxPages) {
            sum += arr[i];
        } else {
            students++;
            sum = arr[i];

            if(students > m)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = arr[0], high = 0, ans = 0;

    // Calculate high = total pages
    for(int i = 0; i < n; i++) {
        high += arr[i];
        if(arr[i] > low)
            low = arr[i]; // max element
    }

    // Binary Search
    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;  // increase
        }
    }

    printf("%d", ans);

    return 0;
}
