#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void spiral_order(int matrix[][4], int m, int n, int output[]) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1, idx = 0;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) output[idx++] = matrix[top][j];
        top++;
        for (int i = top; i <= bottom; ++i) output[idx++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; --j) output[idx++] = matrix[bottom][j];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) output[idx++] = matrix[i][left];
            left++;
        }
    }
}

int main(void) {
    int matrix[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    int output[12];
    spiral_order(matrix, 3, 4, output);
    printf("Spiral order: ");
    for (int i = 0; i < 12; ++i) printf("%d ", output[i]);
    printf("\n");
    return 0;
}