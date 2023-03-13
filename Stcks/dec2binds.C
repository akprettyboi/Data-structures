/*decimal to binary using stacks
#include<stdio.h>
#include<string.h>

int push(int a[], int top, int element)
{
    a[top] = element;
}

int pop(int a[],int top)
{
    return a[top];
}

int main()
{
    int n,r,top=-1;
    int s[20];
    printf("Enter the number in decimal: ");
    scanf("%d",&n);
    if(n == 0)
    {
        printf("The number in binary: %d",n);
        return 0;
    }
    if(n == 1)
    {
        printf("The number in binary: %d",n);
        return 0;
    }
    
    while(n>1)
    {
        r = n%2;
        n = n/2;
        top++;
        push(s,top,r);
    }
    top++;
    push(s,top,n);

    printf("The number in binary: ");
    while(top>-1)
    {
        printf("%d",pop(s,top));
        top--;
    }
    return 0;
}
*/

/*  C Program to convert decimal to binary using stack with struct pointer  */

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);

int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
        DecToBin(num);

        return 0;

}/*End of main()*/

void DecToBin(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
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
}/*End of push()*/

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
}/*End of pop()*/