#include <stdio.h>
#include <string.h>

#define MAX 256  // Total possible ASCII characters

char firstNonRepeating(char *s) {
    int freq[MAX] = {0};   // Frequency array
    int i;

    // Count frequency of each character
    for (i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Find the first character with frequency 1
    for (i = 0; s[i] != '\0'; i++) {
        if (freq[(unsigned char)s[i]] == 1) {
            return s[i];
        }
    }

    return '$';  // If no non-repeating character found
}

int main() {
    char s[100];
    scanf("%s", s);

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}
