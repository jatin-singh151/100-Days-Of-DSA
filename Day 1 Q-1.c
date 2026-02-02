#include <stdio.h>

int main() {
    int n, i, pos, x;
    int arr[100];   

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);
    scanf("%d", &x);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return 0;
    }
  
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = x;

    n++;
  
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
