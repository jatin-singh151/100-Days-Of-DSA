#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

// DFS function to detect cycle
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) { // edge exists
            // If not visited, recurse
            if (!visited[i] && dfs(i))
                return 1;

            // If visited and in recursion stack → cycle
            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to check cycle
int hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    if (hasCycle())
        printf("YES (Cycle exists)\n");
    else
        printf("NO (No cycle)\n");

    return 0;
}
