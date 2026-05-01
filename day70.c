#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <limits.h>

int main(void) {
    int V = 5;
    int E = 8;
    int edges[8][3] = {{0,1,6},{0,3,1},{1,2,5},{1,3,2},{1,4,2},{2,4,5},{3,4,1},{4,2,5}};
    int dist[5];
    for (int i = 0; i < V; ++i) dist[i] = INT_MAX;
    dist[0] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
    printf("Bellman-Ford distances: ");
    for (int i = 0; i < V; ++i) printf("%d ", dist[i]);
    printf("\n");
    return 0;
}