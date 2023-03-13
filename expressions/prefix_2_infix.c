#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Operand stack structure
struct OperandStack {
    int top;
    char arr[MAX_SIZE];
} operandStack;

// Operator stack structure
struct OperatorStack {
    int top;
    char arr[MAX_SIZE];
} operatorStack;

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

// Function to push operator elements into the stack
void pushOperator(char ch) {
    if (operatorStack.top == MAX_SIZE - 1) {
        printf("Operator stack overflow\n");
        return;
    }
    operatorStack.arr[++operatorStack.top] = ch;
}

// Function to pop operator elements from the stack
char popOperator() {
    if (operatorStack.top == -1) {
        printf("Operator stack underflow\n");
        return '\0';
    }
    return operatorStack.arr[operatorStack.top--];
}

// Function to convert
void prefixToInfix(char prefix[]) {
int len = strlen(prefix);
// Initialize the stacks
operandStack.top = -1;
operatorStack.top = -1;

// Traverse the prefix expression
for (int i = len - 1; i >= 0; i--) {
    char ch = prefix[i];

    // If the character is an operand, push it to the operand stack
    if (isOperand(ch)) {
        pushOperand(ch);
    }
    // If the character is an operator
    else if (isOperator(ch)) {
        // Pop two operands from the operand stack
        char op1 = popOperand();
        char op2 = popOperand();

        // Concatenate the operator and operands to form the infix expression
        char temp[3] = {'\0'};
        temp[0] = '(';
        temp[1] = op1;
        temp[2] = ch;
        strcat(temp, op2);
        strcat(temp, ")");

        // Push the infix expression to the operand stack
        pushOperand(temp);
    }
}

// The final infix expression is at the top of the operand stack
printf("Infix expression: %s\n", operandStack.arr[operandStack.top]);
}

int main() {
char prefix[MAX_SIZE];
printf("Enter a prefix expression: ");
scanf("%s", prefix);
prefixToInfix(prefix);
return 0;
}