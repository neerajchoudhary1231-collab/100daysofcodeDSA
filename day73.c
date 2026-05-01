#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int parent[1005];
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void union_set(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) parent[pa] = pb;
}

int main(void) {
    int edges[3][2] = {{1,2},{2,3},{1,3}};
    for (int i = 1; i <= 3; ++i) parent[i] = i;
    for (int i = 0; i < 3; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (find(u) == find(v)) {
            printf("Redundant edge: %d %d\n", u, v);
            return 0;
        }
        union_set(u, v);
    }
    printf("No redundant edge\n");
    return 0;
}