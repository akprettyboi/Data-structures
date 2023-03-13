#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LEN 100
#define MAX_STACK_SIZE 100

// Function to check if a character is an operator
int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

// Function to check the precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char stack[MAX_STACK_SIZE];
    int top = -1;

    for (i = 0; i < strlen(infix); i++) {
        // If the current character is an operand, add it to the postfix expression
        if (!isOperator(infix[i]))
            postfix[j++] = infix[i];

        // If the current character is an operator
        else {
            // If the stack is not empty and the top operator has higher or equal precedence to the current operator
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            // Push the current operator onto the stack
            stack[++top] = infix[i];
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Add null terminator to the postfix expression
}

int main() {
    char infix[MAX_EXPR_LEN];
    char postfix[MAX_EXPR_LEN];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

