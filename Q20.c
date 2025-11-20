#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], result[MAX], indexTop, n;

void topoDFS(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i])
            topoDFS(i);
    }

    result[indexTop--] = node;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    indexTop = n - 1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topoDFS(i);

    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
}

