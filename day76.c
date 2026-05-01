#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <stdlib.h>
struct Node { int v; struct Node* next; };
struct Node* add_edge(struct Node* head, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = head;
    return node;
}

void dfs(int u, struct Node* adj[], int visited[]) {
    visited[u] = 1;
    for (struct Node* p = adj[u]; p != NULL; p = p->next) {
        if (!visited[p->v]) dfs(p->v, adj, visited);
    }
}

int main(void) {
    int n = 4;
    struct Node* adj[5] = {NULL};
    adj[1] = add_edge(adj[1], 2);
    adj[2] = add_edge(adj[2], 1);
    adj[3] = add_edge(adj[3], 4);
    adj[4] = add_edge(adj[4], 3);
    int visited[5] = {0};
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }
    printf("Components: %d\n", count);
    return 0;
}