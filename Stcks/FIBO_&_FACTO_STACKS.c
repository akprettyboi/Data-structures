/******************************************************************************

                            factorial and fibonnaci ( neeed to make the output look better )

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned int arr[MAX_SIZE];
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
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!");
        return -1;
    }
    return stack->arr[stack->top--];
}

void factorial(int n) {
    struct Stack* stack = createStack();

    while (n) {
        push(stack, n--);
    }

    int product = 1;
    while (!isEmpty(stack)) {
        product *= pop(stack);
    }

    printf("Factorial: %d\n", product);
}

void fibonacci(int n) {
    struct Stack* stack = createStack();
    int a = 0, b = 1, x=0;
    int arr2[MAX_SIZE];

    for (int i = 1; i <= n; i++) {
        push(stack, a);
        int next = a + b;
        a = b;
        b = next;
    }

    printf("Fibonacci series: ");
    while (!isEmpty(stack)) {
        //printf("%d ", pop(stack));
        arr2[x] = pop(stack);
        x++;
    }
    /*Another thing to take into account, the function pop() removes and returns the value of the top element in the stack, so if the elements are stored in the array, you will be deleting the elements of the stack, if you need to have a look at the fibonacci series after completing the program you will not have them.*/
    for (int j = x-1 ; j>=0 ; j-- ){
    printf ("%d ", arr2[j]);
}

    
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nEnter your choice\n1.Factorial\n2.Fibonacci Series\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        factorial(n);
        break;
    case 2:
        fibonacci(n);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
    return 0;
}
