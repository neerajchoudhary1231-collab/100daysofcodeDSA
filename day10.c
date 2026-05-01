#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int is_symmetric(int matrix[][3], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) return 0;
        }
    }
    return 1;
}

int is_toeplitz(int matrix[][4], int m, int n) {
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) return 0;
        }
    }
    return 1;
}

int main(void) {
    int matrix1[3][3] = { {1,2,3}, {2,4,5}, {3,5,6} };
    printf("Is symmetric: %s\n", is_symmetric(matrix1, 3) ? "true" : "false");
    int matrix2[3][4] = { {1,2,3,4}, {5,1,2,3}, {9,5,1,2} };
    printf("Is Toeplitz: %s\n", is_toeplitz(matrix2, 3, 4) ? "true" : "false");
    return 0;
}