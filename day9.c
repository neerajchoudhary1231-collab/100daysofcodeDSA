#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void matrix_addition(int mat1[][3], int mat2[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) result[i][j] = mat1[i][j] + mat2[i][j];
    }
}

void transpose(int matrix[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) result[j][i] = matrix[i][j];
    }
}

int main(void) {
    int mat1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int mat2[2][3] = { {7, 8, 9}, {10, 11, 12} };
    int result[2][3];
    matrix_addition(mat1, mat2, result, 2, 3);
    printf("Matrix addition result:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) printf("%d ", result[i][j]);
        printf("\n");
    }
    int trans[3][2];
    transpose(mat1, trans, 2, 3);
    printf("Transpose:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) printf("%d ", trans[i][j]);
        printf("\n");
    }
    return 0;
}