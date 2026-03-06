#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // If operand
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator
        else {
            int val1 = pop();
            int val2 = pop();

            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }

        i++;
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter Postfix Expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
