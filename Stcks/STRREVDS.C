
//string reverse using stacks
#include<stdio.h>
#include<string.h>

char pop(char a[], int top)
{
    return a[top];
}

char push(char a[], int top, char element)
{
    a[top] = element;
}

int main()
{
    char str[20];
    char s[20];
    int i=0,j,top=-1;
    printf("ENTER YOUR STRING \n");
    gets(str);
    for(i=0; i<strlen(str); i++)
    {
        top++;
        push(s,top,str[i]);
    }
      
    printf("REVERSE STRING IS : \n");

    while(top >= 0)
    {
        printf("%c",pop(s,top));
        top--;
    }
    return 0;
}