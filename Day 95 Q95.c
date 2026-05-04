#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert in sorted order (for each bucket)
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or empty list
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Traverse and insert
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data <= value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    int i;

    // Step 1: Create buckets
    struct Node* buckets[n];
    for(i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements into buckets
    for(i = 0; i < n; i++) {
        int index = n * arr[i];  // mapping to bucket
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for(i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d real numbers in range [0,1):\n", n);
    for(i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%.3f ", arr[i]);

    return 0;
}
