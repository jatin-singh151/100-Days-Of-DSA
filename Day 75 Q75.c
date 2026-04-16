#include <stdio.h>
#include <stdlib.h>

// Simple hash map using array (for demo, adjust size if needed)
#define MAX 10000

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0, max_len = 0;

    // Initialize hash array with -1
    int hash[MAX];
    for (int i = 0; i < MAX; i++)
        hash[i] = -2;  // -2 means not visited

    hash[0] = -1;  // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int key = sum + 5000; // shift to avoid negative index

        if (hash[key] != -2) {
            int len = i - hash[key];
            if (len > max_len)
                max_len = len;
        } else {
            hash[key] = i;
        }
    }

    printf("%d\n", max_len);
    return 0;
}
