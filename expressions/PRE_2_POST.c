#include <stdio.h>
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

// Function to perform the operation
int performOperation(int op1, int op2, char op) {
    switch (op) {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
    return -1;
}

// Function to convert prefix to postfix
void prefixToPostfix(char prefix[]) {
    int len = strlen(prefix);
    char postfix[MAX_SIZE];
    int j = -1;

    // Traverse the prefix expression
    for (int i = len - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            postfix[++j] = prefix[i];
        } else if (isOperator(prefix[i])) {
            postfix[++j] = pop();
            postfix[++j] = pop();
            postfix[++j] = prefix[i];
        }
    }

    postfix[++j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression
    int resultStack[MAX_SIZE], resultTop = -1;
    for (int i = 0; i < j; i++) {
        if (isOperand(postfix[i])) {
            resultStack[++resultTop] = postfix[i] - '0';
        } else if (isOperator(postfix[i])) {
            int op2 = resultStack[resultTop--];
            int op1 = resultStack[resultTop--];
            resultStack[++resultTop] = performOperation(op1, op2, postfix[i]);
}
}
printf("Result: %d\n", resultStack[resultTop]);
}

int main() {
stk.top = -1;
char prefix[MAX_SIZE];
printf("Enter a prefix expression: ");
scanf("%s", prefix);

prefixToPostfix(prefix);
return 0;
}

