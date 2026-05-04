#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting by start time
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// -------- Min Heap Functions --------
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        } else break;
    }
}

// Insert into heap
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Remove min (top)
int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// Get min
int top(int heap[]) {
    return heap[0];
}

// -------- Main Logic --------
int minMeetingRooms(Interval arr[], int n) {
    // Sort by start time
    qsort(arr, n, sizeof(Interval), compare);

    int heap[n]; // min-heap of end times
    int size = 0;

    // Add first meeting
    push(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        // If room becomes free
        if (arr[i].start >= top(heap)) {
            pop(heap, &size);
        }
        // Allocate current meeting
        push(heap, &size, arr[i].end);
    }

    return size;
}

// -------- Driver Code --------
int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    int rooms = minMeetingRooms(arr, n);
    printf("Minimum number of rooms required: %d\n", rooms);

    return 0;
}
