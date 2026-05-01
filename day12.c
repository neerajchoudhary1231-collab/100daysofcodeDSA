#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int is_identity(int matrix[][3], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) return 0;
        }
    }
    return 1;
}

void rotate(int matrix[][3], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = tmp;
        }
    }
}

int main(void) {
    int id[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
    printf("Is identity: %s\n", is_identity(id, 3) ? "true" : "false");
    int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    rotate(matrix, 3);
    printf("Rotated matrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}