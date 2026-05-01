#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <stdlib.h>

void dfs(int node, int vis[], int adj[][100], int V, int* stack, int* top) {
    vis[node] = 1;
    for (int i = 0; i < V; ++i) {
        if (adj[node][i] && !vis[i]) dfs(i, vis, adj, V, stack, top);
    }
    stack[(*top)++] = node;
}

int main(void) {
    int V = 4;
    int adj[100][100] = {{0}};
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    int vis[100] = {0};
    int stack[100];
    int top = 0;
    for (int i = 0; i < V; ++i) if (!vis[i]) dfs(i, vis, adj, V, stack, &top);
    printf("Topological order: ");
    for (int i = top - 1; i >= 0; --i) printf("%d ", stack[i]);
    printf("\n");
    return 0;
}