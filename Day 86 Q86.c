#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow, use long long
        long long sq = (long long)mid * mid;

        if (sq == n)
            return mid;
        else if (sq < n) {
            ans = mid;   // store possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));
    return 0;
}
