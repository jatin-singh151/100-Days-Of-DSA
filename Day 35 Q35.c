#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Print queue from front to rear
void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free memory
void freeQueue(struct Queue* q) {
    struct Node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    int n, value;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    printQueue(q);
    freeQueue(q);

    return 0;
}
```

**How it works:**

- **Node** holds an `int data` and a `next` pointer — classic linked list node.
- **Queue** has `front` and `rear` pointers for O(1) enqueue and access.
- **enqueue()** — creates a new node, links it to `rear`, and updates `rear`.
- **printQueue()** — traverses from `front` to `rear`, printing each value space-separated.
- **freeQueue()** — walks the list freeing each node, then frees the queue struct itself (no memory leaks).

**Example:**
```
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
