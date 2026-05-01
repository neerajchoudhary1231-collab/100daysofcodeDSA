#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int graph[4][4] = {
    {0,1,0,0},
    {1,0,1,0},
    {0,1,0,1},
    {0,0,1,0}
};

int main(void) {
    int color[4] = {-1,-1,-1,-1};
    int queue[4];
    int qf = 0, qr = 0;
    int start = 0;
    color[start] = 0;
    queue[qr++] = start;
    while (qf < qr) {
        int u = queue[qf++];
        for (int v = 0; v < 4; ++v) {
            if (graph[u][v]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue[qr++] = v;
                } else if (color[v] == color[u]) {
                    printf("Not bipartite\n");
                    return 0;
                }
            }
        }
    }
    printf("Bipartite\n");
    return 0;
}