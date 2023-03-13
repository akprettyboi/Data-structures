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

// Function to check the precedence of operators
int precedence(char ch) {
    switch (ch) {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
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

// Function to convert infix to prefix
void infixToPrefix(char infix[]) {
    int len = strlen(infix);
    char prefix[MAX_SIZE];
    int j = -1;

    // Reverse the infix expression
    for (int i = 0; i < len / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }

    // Initialize the stack
    stk.top = -1;

    // Traverse the reversed infix expression
    for (int i = 0; i < len; i++) {
        if (isOperand(infix[i])) {
            prefix[++j] = infix[i];
        } else if (isOperator(infix[i])) {
            while (stk.top != -1 && precedence(stk.arr[stk.top]) >= precedence(infix[i])) {
                prefix[++j] = pop();
            }
            push(infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (stk.arr[stk.top] != '(') {
                prefix[++j] = pop();
            }
        }
    }
}
    
    int main() {
char infix[MAX_SIZE];
char prefix[MAX_SIZE];
printf("Enter an infix expression: ");
scanf("%s", infix);
infixToPrefix(infix);
printf("The prefix expression is: %s\n", prefix);
return 0;
}

