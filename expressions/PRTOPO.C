#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
# define MAX 50
char opnds[50][80],oprs[50];
int  topr=-1,topd=-1,stackn[MAX],topn = -1;
void pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}
char *popd()
{
    return(opnds[topd--]);
}

void pushr(char opr)
{
    oprs[++topr]=opr;
}
char popr()
{
    return(oprs[topr--]);
}
int empty(int t)
{
    if( t == 0) return(1);
    return(0);
}

void pushn(int item)
{
    if(topn == (MAX - 1))
    {
	printf("Stack Overflow\n");
	return;
    }
    topn++;
    stackn[topn] = item;
}
int popn()
{
    if(topn == -1)
    {
	printf("Stack Underflow\n");
	exit(1);
    }
    return(stackn[topn--]);
}


void cal(char exp[])
{
    int num, i, a , b, ans;
    printf("\n");
    for(i = 0; i <= strlen(exp); i++)
    {
	if(exp[i] >= 'a' && exp[i] <= 'z')
	{
	    printf("Enter value for %c : ", exp[i]);
	    scanf("%d", &num);
	    pushn(num);
	}

	else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
	{
	    a = popn();
	    b = popn();
	    switch(exp[i])
	    {
		case '+':
		    ans = b + a;
		break;

		case '-':
		    ans = b - a;
		break;

		case '*':
		    ans = b * a;
		break;

		case '/':
		    ans = b / a;
		break;

		default:
		    ans = 0;
	    }
	    pushn(ans);
	}
    }
    printf("\nAnswer of the equation is : %d", popn());
}


void main()
{
    char prfx[50],ch,str[50],opnd1[50],opnd2[50],opr[2];
    int i=0,opndcnt=0;

    printf("Give an Expression = ");
    gets(prfx);

    //strrev(prfx);
    printf(" Given Prefix Expression : %s\n",prfx);
    while( (ch=prfx[i++]) != '\0')
    {
        if(isalnum(ch))
        {
            str[0]=ch; str[1]='\0';
            pushd(str); opndcnt++;
            if(opndcnt >= 2)
            {
                strcpy(opnd2,popd());
                strcpy(opnd1,popd());                
                strcpy(str,opnd1);
                strcat(str,opnd2);
                ch=popr();
                opr[0]=ch;opr[1]='\0';
                strcat(str,opr);
                pushd(str);
                opndcnt-=1;
            }
        }
        else
        {
            pushr(ch);
            if(opndcnt==1)opndcnt=0;  
        }
    }
    if(!empty(topd))
    {
        strcpy(opnd2,popd());
        strcpy(opnd1,popd());
        strcat(str,opnd1);
        strcat(str,opnd2);
        ch=popr();
        opr[0]=ch;opr[1]='\0';
        strcat(str,opr);
        pushd(str);
    }
    printf(" postfix Expression: ");
    puts(opnds[topd]);
    
    strrev(prfx);
    cal(prfx);
    getch();
}