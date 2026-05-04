#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting by start time
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {
    if (n <= 0) return;

    // Step 1: Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array for result
    Interval result[n];
    int j = 0;

    // Add first interval
    result[j] = arr[0];

    // Step 2: Merge
    for (int i = 1; i < n; i++) {
        // If overlapping
        if (arr[i].start <= result[j].end) {
            // Merge by updating end
            if (arr[i].end > result[j].end)
                result[j].end = arr[i].end;
        } else {
            // No overlap → move to next
            j++;
            result[j] = arr[i];
        }
    }

    // Step 3: Print merged intervals
    printf("Merged intervals:\n");
    for (int i = 0; i <= j; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}
