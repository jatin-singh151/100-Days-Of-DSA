#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void init() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // -1 means empty
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);

    // If empty slot found
    if(hashTable[index] == -1) {
        hashTable[index] = key;
        return;
    }

    // Quadratic probing
    for(int i = 1; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }

    printf("Hash Table is Full!\n");
}

// Display hash table
void display() {
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : EMPTY\n", i);
    }
}

int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    return 0;
}
