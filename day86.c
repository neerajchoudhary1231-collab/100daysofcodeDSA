#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int my_sqrt(int x) {
    if (x < 2) return x;
    int low = 1, high = x / 2, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sq = (long long)mid * mid;
        if (sq == x) return mid;
        if (sq < x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    printf("Sqrt: %d\n", my_sqrt(15));
    return 0;
}