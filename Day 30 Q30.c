#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->coeff);

        if (temp->exp > 0)
            printf("x");

        if (temp->exp > 1)
            printf("^%d", temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    displayPolynomial(head);

    return 0;
}
