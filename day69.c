#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <limits.h>

int min_distance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; ++v) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main(void) {
    int V = 5;
    int graph[5][5] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };
    int dist[5];
    int sptSet[5] = {0};
    for (int i = 0; i < V; ++i) dist[i] = INT_MAX;
    dist[0] = 0;
    for (int count = 0; count < V - 1; ++count) {
        int u = min_distance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; ++v) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Distances: ");
    for (int i = 0; i < V; ++i) printf("%d ", dist[i]);
    printf("\n");
    return 0;
}