#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Operand stack structure
struct OperandStack {
    int top;
    char arr[MAX_SIZE];
} operandStack;

// Function to check if the character is an operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}

// Function to check if the character is an operand
int isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}

// Function to push operand elements into the stack
void pushOperand(char ch) {
    if (operandStack.top == MAX_SIZE - 1) {
        printf("Operand stack overflow\n");
        return;
    }
    operandStack.arr[++operandStack.top] = ch;
}

// Function to pop operand elements from the stack
char popOperand() {
    if (operandStack.top == -1) {
        printf("Operand stack underflow\n");
        return '\0';
    }
    return operandStack.arr[operandStack.top--];
}

// Function to convert postfix to infix
void postfixToInfix(char postfix[]) {
    int len = strlen(postfix);
    char temp[MAX_SIZE];
    int j = -1;
    char op1, op2;

    // Traverse the postfix expression
    for (int i = 0; i < len; i++) {
        if (isOperand(postfix[i])) {
            pushOperand(postfix[i]);
        } else if (isOperator(postfix[i])) {
            op2 = popOperand();
            op1 = popOperand();
            j = -1;
            temp[++j] = '(';
            temp[++j] = op1;
            temp[++j] = postfix[i];
            temp[++j] = op2;
            temp[++j] = ')';
            temp[++j] = '\0';
            pushOperand(temp);
        }
    }

    printf("Infix expression: %s\n", operandStack.arr[operandStack.top]);
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    return 0;
}
