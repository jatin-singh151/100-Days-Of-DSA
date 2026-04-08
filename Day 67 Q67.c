#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Stack
int stack[MAX];
int top = -1;

// Visited array
int visited[MAX];

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(struct Graph* graph, int v) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(graph, temp->vertex);
        }
        temp = temp->next;
    }

    // push after visiting all neighbors
    push(v);
}

// Topological Sort
void topologicalSort(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfs(graph, i);
        }
    }

    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Driver code
int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
