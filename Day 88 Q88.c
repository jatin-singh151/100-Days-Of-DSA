#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if k cows can be placed with minimum distance 'dist'
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;
    int last_pos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - last_pos >= dist) {
            count++;
            last_pos = stalls[i];
        }
        if(count >= k)
            return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    // Sort stall positions
    qsort(stalls, n, sizeof(int), cmp);

    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = 0;

    // Binary search on answer
    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}
