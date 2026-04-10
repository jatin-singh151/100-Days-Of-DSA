#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100

// Min Heap Node
struct MinHeapNode {
    int v;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct MinHeapNode* array[V];
};

// Create new node
struct MinHeapNode* newNode(int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

// Swap nodes
void swap(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->array[smallest], &heap->array[idx]);
        heapify(heap, smallest);
    }
}

// Extract min
struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct MinHeapNode* root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    heapify(heap, 0);
    return root;
}

// Dijkstra function
void dijkstra(int graph[V][V], int n, int src) {
    int dist[V];

    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    // Source
    dist[src] = 0;
    heap->array[heap->size++] = newNode(src, 0);

    while (heap->size > 0) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                heap->array[heap->size++] = newNode(v, dist[v]);
            }
        }
    }

    // Print result
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Driver
int main() {
    int n = 5;

    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    dijkstra(graph, n, 0);

    return 0;
}
