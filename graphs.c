#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1; // remove this line for directed graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    resetVisited();
    BFS(start);

    resetVisited();
    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}
