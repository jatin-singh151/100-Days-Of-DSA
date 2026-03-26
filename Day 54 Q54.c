#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree from level-order input (-1 = NULL)
Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* root = newNode(arr[0]);
    Node* queue[MAXN];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        Node* curr = queue[front++];
        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void zigzagTraversal(Node* root) {
    if (!root) return;

    Node* queue[MAXN];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int level = 0;          // 0 = left-to-right, 1 = right-to-left
    int result[MAXN];
    int printed = 0;

    while (front < rear) {
        int size = rear - front;  // number of nodes at current level
        int levelVals[MAXN];

        for (int i = 0; i < size; i++) {
            Node* curr = queue[front++];
            levelVals[i] = curr->val;
            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        // Store in zigzag order
        if (level % 2 == 0) {
            // Left to right
            for (int i = 0; i < size; i++)
                result[printed++] = levelVals[i];
        } else {
            // Right to left
            for (int i = size - 1; i >= 0; i--)
                result[printed++] = levelVals[i];
        }
        level++;
    }

    // Print result
    for (int i = 0; i < printed; i++) {
        if (i) printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    zigzagTraversal(root);
    return 0;
}
```
