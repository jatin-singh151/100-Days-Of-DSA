#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, val;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *intersectNode = NULL;

 
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        if (head1 == NULL) {
            head1 = newNode(val);
            temp = head1;
        } else {
            temp->next = newNode(val);
            temp = temp->next;
        }
        if (i == n / 2)  
            intersectNode = temp;
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        if (head2 == NULL) {
            head2 = newNode(val);
            temp = head2;
        } else {
            temp->next = newNode(val);
            temp = temp->next;
        }
    }

    temp->next = intersectNode;

    struct Node* result = getIntersection(head1, head2);

    if (result)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}
