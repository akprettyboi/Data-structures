//parentheses validity using stacks
#include<stdio.h>
#include<string.h>

int stackempty(int top)
{
    if(top == -1)
    return 1;

    else
    return -1;
}

int push(char a[], int top, char element)
{
    a[top] = element;
}

char pop(char a[], int top)
{
    if((stackempty(top)) == -1)
    {
        return a[top];
    }
    else
    {
        return -1;
    }
}

int main()
{
    char str[50] = "7-[((X*((X+++++Y)/(J-3))+Y)/(4-2.5))]";
    printf("String Length: %d\n",strlen(str));
    char s[50];
    int i,top=-1;
    char check;
    for(i=0; i<strlen(str); i++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            top++;
            push(s,top,str[i]);
        }
        if(str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            check = pop(s,top);
            top--;
            if(check == -1)
            {
                printf("The string is invalid");
                return 0;
            }
            else
            {
                switch(str[i])
                {
                case '}':
                if(check != '{')
                {
                    printf("The string is invalid");
                    return 0;
                }
                break;

                case ')':
                if(check != '(')
                {
                    printf("The string is invalid");
                    return 0;
                }
                break;

                case ']':
                if(check != '[')
                {
                    printf("The string is invalid");
                    return 0;
                }
                break;
                }
            }
        }
    }
    if(stackempty(top) == 1)
    {
        printf("The string is valid");
    }
    else
    {
        printf("The string is invalid");
        return 0;
    }
}

//parentheses validity using stacks pointer struct
#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); 
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()
{
    char * exp = "((8)(*--$$9))";
    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}