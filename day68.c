#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <stdlib.h>

int main(void) {
    int V = 4;
    int adj[4][4] = {{0}};
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    int indegree[4] = {0};
    for (int i = 0; i < V; ++i) for (int j = 0; j < V; ++j) if (adj[i][j]) indegree[j]++;
    int queue[4], front=0, rear=0;
    for (int i = 0; i < V; ++i) if (indegree[i] == 0) queue[rear++] = i;
    printf("Kahn order: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < V; ++v) {
            if (adj[u][v] && --indegree[v] == 0) queue[rear++] = v;
        }
    }
    printf("\n");
    return 0;
}