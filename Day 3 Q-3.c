#include <stdio.h>

int main() {
    int n, k;
    int count = 0;
    int found = -1;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        count++;   

        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", count);

    return 0;
}
