#include <stdio.h>

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int i;

    // Step 1: Find maximum element
    int max = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create frequency array
    int count[max + 1];
    for(i = 0; i <= max; i++)
        count[i] = 0;

    for(i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Compute prefix sums
    for(i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 4: Build output array
    int output[n];
    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy output back to original array
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function
int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements (non-negative integers):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
