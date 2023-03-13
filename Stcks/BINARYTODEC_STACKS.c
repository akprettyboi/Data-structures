/******************************************************************************

                            binary to decimal using stacks

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void BinToDec(int num);

int main()
{
        int num;
        printf("Enter an integer in binary: ");
        scanf("%d",&num);
        printf("Decimal equivalent is: ");
        BinToDec(num);
        return 0;
}

void BinToDec(int num)
{
        int stack[MAX], top=-1, rem, decimal=0, base=1;
        while(num!=0)
        {
                rem = num%10;
                push(rem, &top, stack);
                num/=10;
        }
        while(top!=-1)
        {
                rem = pop(&top, stack);
                decimal += rem*base;
                base *= 2;
        }
        printf("%d\n", decimal);
}

void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}
