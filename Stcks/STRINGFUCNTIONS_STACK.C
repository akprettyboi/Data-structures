
#include<stdio.h>
#include<string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
int top = -1;
int t = -1;
char stack[MAX];
char stack2[MAX];

int stackFull()    //Checks if Stack is Full 
{    
    if(top >= MAX-1)
        return TRUE;
    else
        return FALSE;
}
 
int stackEmpty()  // Checks if Stack is Empty 
{
 if(top == -1)
     return TRUE;
 else
     return FALSE;
}

int stackFull2()    //Checks if Stack is Full 
{    
    if(t >= MAX-1)
        return TRUE;
    else
        return FALSE;
}
 
int stackEmpty2()  // Checks if Stack is Empty 
{
 if(t == -1)
     return TRUE;
 else
     return FALSE;
}

void push(char element)
{
     if (stackFull())
        printf("Stack is Full \n");

    else 
        stack[top + 1] = element;
        top++;
        
}
 
void push2(char element2)
{
     if (stackFull2())
        printf("Stack is Full \n");

    else 
        stack2[t + 1] = element2;
        t++;
        
}

char pop()
{
     if (stackEmpty())
        printf("Stack is Empty \n");

    else 
     top = top - 1;
     return stack[top + 1];

}
char pop2()
{
     if (stackEmpty2())
        printf("Stack is Empty \n");

    else 
     t = t - 1;
     return stack2[t + 1];

}

void str_palindrome(char str[])
{
     int i;
     char element=0;
     int len;
     len = strlen(str);
     
     for(i = 0; i < len; i++)
    {
        push(str[i]);
    }

   for(i = 0; i < len; i++)
   {
    if(str[i] == pop() )
    {
        element ++;  
    }

    }
    if(len == element )
    printf("This String is palindrome\n ");
    
    else
    printf("The String is not palindrome");
    

}

void str_reverse(char str[])
{
     int i;
     int len;
     len = strlen(str);
     
        for(i=0; i< len ;i++)
        {
          push(str[i]);
        }
        
        for(i=0; i<len ;i++)
        {
          str[i]=pop();
        }

    printf("reversed String is: %s\n",str);
}

void str_concat(char str1[] , char str2[])
{
    
    int i,l1,l2;
    
    
    l1=strlen(str1);
    for(i=0;i<l1;i++)
    {
	push(str1[i]);
    }

 
    l2=strlen(str2);
    for(i=0;i<l2;i++)
    {
        push(str2[i]);
    } 
    printf("the concated string is:");
    for(i=0;i<(l1+l2);i++)
    {
        char s2=pop();
        push2(s2);
     } 
     for(i=0;i<(l1+l2);i++)
    {
        char s3=pop2();
        printf("%c",s3);
     }
     top=-1;
     t=-1;
}

void str_compare(char str[] , char str2[])
{
    int i,flag=0;
    int len,len2;
    len = strlen(str);
    len2 = strlen(str2);
    strrev(str);
    strrev(str2);
    
    for(i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for(i = 0; i < len2; i++)
    {
        push(str2[i]);
    }


 for(i=0 ; str[i]!= '\0' || str2[i]!='\0' ; i++)
 {
    if(str[i] == str2[i])
   {
     flag = 1;
     break;
   }
    if(str[i]>str2[i])
   {
     flag = 2;
     break;
   }
}
   
     
  if (flag == 1)
  printf("Strings are Same !");

  else if (flag == 2) 
  printf("String 1 is bigger in ascii value and both strings are not same !");

  else 
  printf("String 2 is bigger and both strings are not same !");
 
}


void main()  
{
    int option,len;
    char Stack[MAX];
    char str[MAX];
    char str2[MAX];
    clrscr();

    printf("Enter Option for particular Operation to be performed \nOption 1 = Palindrome \nOption 2 = String reverseerse \nOption 3 = String Concatenate \nOption 4 = String Compare \nOption 5 = To Exit");
 do
 {
    printf("\nEnter Option : ");
    scanf("%d",&option);
    printf("\n\n");
    switch (option)
    {
    case 1:
	 printf("Operation Performing is Palindrome \n");
	 printf("Enter a string : ");
	 scanf("%s",str);
	 str_palindrome(str);
	 printf("\n\n");
	 break;

    case 2:
	 printf("Operation Performing is String reverse \n");
	 printf("Enter a string : ");
	 scanf("%s",str);
	 str_reverse(str);
	 printf("\n\n");
	 break;

    case 3:
	 printf("Operation Performing is String Concatenation \n");
	 printf("Enter a string  1 : ");
	 scanf("%s",str);
	 printf("Enter a string  2 : ");
	 scanf("%s",str2);
	 str_concat(str ,str2);
	 printf("\n\n");
	 break;

    case 4:
	 printf("Operation Performing is String Compare \n");
	 printf("Enter a string  1 : ");
	 scanf("%s",str);
	 printf("Enter a string  2 : ");
	 scanf("%s",str2);
	 str_compare(str ,str2);
	 printf("\n\n");
	 break;

    case 5:
	 printf("Code Exited");
	 break;

    default: printf("Option not avalible ! \n");
	break;
    }
 }while(option!=5);
 getch();
}