#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <stdlib.h>

void dfs1(int u, int visited[], int graph[5][5], int n, int stack[], int* top) {
    visited[u] = 1;
    for (int v = 0; v < n; ++v) if (graph[u][v] && !visited[v]) dfs1(v, visited, graph, n, stack, top);
    stack[(*top)++] = u;
}

void dfs2(int u, int visited[], int rev[5][5], int n) {
    visited[u] = 1;
    for (int v = 0; v < n; ++v) if (rev[u][v] && !visited[v]) dfs2(v, visited, rev, n);
}

int main(void) {
    int n = 5;
    int graph[5][5] = {{0}};
    graph[0][1] = graph[1][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][4] = 1;
    int rev[5][5] = {{0}};
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (graph[i][j]) rev[j][i] = 1;
    int visited[5] = {0};
    int stack[5], top = 0;
    for (int i = 0; i < n; ++i) if (!visited[i]) dfs1(i, visited, graph, n, stack, &top);
    for (int i = 0; i < n; ++i) visited[i] = 0;
    int scc = 0;
    while (top > 0) {
        int u = stack[--top];
        if (!visited[u]) {
            dfs2(u, visited, rev, n);
            scc++;
        }
    }
    printf("SCC count: %d\n", scc);
    return 0;
}