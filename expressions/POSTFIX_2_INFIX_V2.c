#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    char arr[MAX_SIZE];
} stk;

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

// Function to push elements into the stack
void push(char ch) {
    if (stk.top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stk.arr[++stk.top] = ch;
}

// Function to pop elements from the stack
char pop() {
    if (stk.top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stk.arr[stk.top--];
}

// Function to convert postfix to infix
void postfixToInfix(char postfix[]) {
    int len = strlen(postfix);

    // Traverse the postfix expression
    for (int i = 0; i < len; i++) {
        if (isOperand(postfix[i])) {
            push(postfix[i]);
        } else if (isOperator(postfix[i])) {
            char op1 = pop();
            char op2 = pop();
            char temp[MAX_SIZE];
            snprintf(temp, sizeof temp, "(%c%c%c)", op2, postfix[i], op1);
            push(temp);
        }
    }

    printf("Infix expression: %s\n", pop());
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    return 0;
}

