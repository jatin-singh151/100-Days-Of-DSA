#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int firstIndex[26];
    
    // Initialize all with -1
    for (int i = 0; i < 26; i++)
        firstIndex[i] = -1;

    int minSecondIndex = INT_MAX;
    char result = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (firstIndex[idx] == -1) {
            // First occurrence
            firstIndex[idx] = i;
        } else {
            // Second occurrence
            if (i < minSecondIndex) {
                minSecondIndex = i;
                result = s[i];
            }
        }
    }

    if (result == -1)
        printf("-1");
    else
        printf("%c", result);

    return 0;
}
