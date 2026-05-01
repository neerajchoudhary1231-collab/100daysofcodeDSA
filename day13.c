#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int diagonal_sum(int matrix[][3], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += matrix[i][i];
    return sum;
}

void set_zeroes(int matrix[][4], int m, int n) {
    bool row[3] = {false}, col[4] = {false};
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (matrix[i][j] == 0) { row[i] = true; col[j] = true; }
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (row[i] || col[j]) matrix[i][j] = 0;
}

int main(void) {
    int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    printf("Diagonal sum: %d\n", diagonal_sum(matrix, 3));
    int matrix2[3][4] = { {1,1,1,0},{1,0,1,1},{1,1,1,1} };
    set_zeroes(matrix2, 3, 4);
    printf("Zeroed matrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) printf("%d ", matrix2[i][j]);
        printf("\n");
    }
    return 0;
}