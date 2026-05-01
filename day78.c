#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <limits.h>
int main(void) {
    int n = 5;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int selected[5] = {0};
    selected[0] = 1;
    int edges = 0, total = 0;
    while (edges < n - 1) {
        int min = INT_MAX, x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (selected[i]) {
                for (int j = 0; j < n; ++j) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        total += min;
        edges++;
    }
    printf("MST weight: %d\n", total);
    return 0;
}