#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n, graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX], timeCounter;

int isArticulation = 0;

void DFS(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                parent[v] = u;
                children++;
                DFS(v);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (parent[u] == -1 && children > 1)
                    isArticulation = 1;

                if (parent[u] != -1 && low[v] >= disc[u])
                    isArticulation = 1;
            }
            else if (v != parent[u]) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    DFS(0);

    if (!isArticulation)
        printf("Graph is Bi-Connected\n");
    else
        printf("Graph is NOT Bi-Connected\n");

    return 0;
}

