#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main(void) {
    int V = 4;
    int adj[4][4] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    int visited[4] = {0};
    int rec_stack[4] = {0};
    int cycle = 0;
    void dfs(int node) {
        visited[node] = 1;
        rec_stack[node] = 1;
        for (int i = 0; i < V; ++i) {
            if (adj[node][i]) {
                if (!visited[i]) dfs(i);
                else if (rec_stack[i]) cycle = 1;
            }
        }
        rec_stack[node] = 0;
    }
    dfs(0);
    printf("Cycle: %s\n", cycle ? "yes" : "no");
    return 0;
}