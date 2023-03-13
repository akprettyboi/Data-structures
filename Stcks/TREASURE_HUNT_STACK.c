/******************************************************************************

                            treasue hunt ( make the output look better)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int arr[MAX_SIZE];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int peek(struct Stack* stack) {
    return stack->arr[stack->top];
}

void push(struct Stack* stack, int item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow!");
        return;
    }
    stack->arr[++stack->top] = item;
    //printf("%d is pushed to stack\n", item);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!");
        return 0;
    }
    return stack->arr[stack->top--];
}

void decimalToBinary(int decimal) {
    struct Stack* stack = createStack();

    int remainder;

    while (decimal > 0) {
        remainder = decimal % 2;
        push(stack, remainder);
        decimal = decimal / 2;
    }

    printf("\nDecimal to Binary conversion: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }
    printf("\n");
}

void treasureHunt() {
    printf("You are in room 1\n");
    printf("Moving to room 2\n");
    printf("Moving to room 3\n");
   
    printf("Moving to room 4\n");
    printf("You are in room 5\n");
    printf("Found the box with decimal number.\n");
    printf("Enter the decimal number: ");
    int decimal;
    scanf("%d", &decimal);
    printf("Converting decimal number to binary code\n");
    decimalToBinary(decimal);
    printf("Using binary code to unlock the door\n");
    printf("Moving to room 4\n");
    printf("Found the box with decimal number.\n");
    printf("Enter the decimal number: ");
    int decimal2;
    scanf("%d", &decimal2);
    printf("Converting decimal number to binary code\n");
    decimalToBinary(decimal2);
    printf("Using binary code to unlock the door\n");
    printf("Moving to room 3\n");
    printf("Found the box with decimal number.\n");
    printf("Enter the decimal number: ");
    int decimal3;
    scanf("%d", &decimal3);
    printf("Converting decimal number to binary code\n");
    decimalToBinary(decimal3);
    printf("Using binary code to unlock the door\n");
    printf("Moving to room 2\n");
    printf("Found the box with decimal number.\n");
    printf("Enter the decimal number: ");
    int decimal4;
    scanf("%d", &decimal4);
    printf("Converting decimal number to binary code\n");
    decimalToBinary(decimal4);
    printf("Using binary code to unlock the door\n");
    printf("Moving to room 1\n");
    printf("Reaching the treasure room.\n");
    printf("Using binary code to unlock the treasure\n");
    printf("Got the treasure.\n");
    printf("Mission Accompished!\n");

}

    /*printf("Reaching room 5\n");
    printf("Found the box with decimal number.\n");
    printf("Enter the decimal number: ");
    int decimal;
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    printf("Using binary code to unlock treasure in room 1\n");
    printf("Got the treasure.\n");
    printf("Moving back to room 5\n");
    printf("Moving back to room 4\n");
    printf("Moving back to room 3\n");
    printf("Moving back to room 2\n");
    printf("Reached room 1\n");
    printf("Mission Accomplished!\n");
}*/

int main() {
    treasureHunt();
    return 0;
}

