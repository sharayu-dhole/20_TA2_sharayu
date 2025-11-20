#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX];
int n;


int queue[MAX], front = 0, rear = 0;

void BFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front != rear) {
        int node = queue[front++];

        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i])
            DFSUtil(i);
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("DFS: ");
    DFSUtil(start);
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    BFS(0);
    DFS(0);

    return 0;
}

