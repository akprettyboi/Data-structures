/******************************************************************************

                            NAMES WALA FROM STACK NEEDS WORK

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char arr[MAX_SIZE][MAX_SIZE];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char* peek(struct Stack* stack) {
    return stack->arr[stack->top];
}

void push(struct Stack* stack, char* item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow!");
        return;
    }
    strcpy(stack->arr[++stack->top],item);
    printf("%s pushed to stack\n", item);
}

char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!");
        return "";
    }
    return stack->arr[stack->top--];
}

/*void order_name(char *name) {
    struct Stack* stack = createStack();
    int i=0,j=0;
    char temp[100];
    int len = strlen(name);
    for (i=0; i <= len; i++) {
        if (name[i] == ' ' || name[i] == '\0') {
            temp[j] = '\0';
            push(stack,temp);
            j=0;
        }
        else {
            temp[j] = name[i];
            j++;
        }
    }
    printf("\n Name in the order of Surname, First name, and Middle name :  ");
    for (i = 0; i < 3; i++) {
        printf("%s ",pop(stack));
    }
    printf("\n");
}*/

void order_name(char *name) {
    struct Stack* stack = createStack();
    int i=0,j=0;
    char temp[100];
    int len = strlen(name);
    for (i=0; i <= len-1; i++) {
        if (name[i] == ' ' ) {
            temp[j] = '\0';
            push(stack,temp);
            j=0;
        }
        else {
            temp[j] = name[i];
            j++;
        }
    }
    temp[j] = '\0';
    push(stack,temp);

    printf("\n Name in the order of Surname, First name, and Middle name :  ");
    printf("%s ",pop(stack));
    for (i = 0; i < 2; i++) {
        printf("%s ",pop(stack));
    }
    printf("\n");
}


int main() {
    char name[100];
    printf("Enter your name in the format of First Middle Surname: ");
    fgets(name,100,stdin);
    order_name(name);
    return 0;
}
