//THIS LITTLE BIT OF REFINERY SOLVE IT AND MAKE NESSCARYRY CHANGES

#include<math.h>
#include<stdio.h>
#include<conio.h>
#define MAX 17
typedef struct node
  {
int coeff;
struct node *next;
  }node;
node *  init();
void read(node *h1);
void print(node *h1);
node * add(node *h1,node *h2);
node * multiply(node *h1,node *h2);
/*Polynomial is stored in a linked list, ith node  gives coefficient of x^i .
  a polynomial 3x^2 + 12x^4 will be represented as (0,0,3,0,12,0,0,….)
*/
void main()
{
node *h1=NULL,*h2=NULL,*h3=NULL;
int option;
clrscr();
do
{
printf("\n1 : create 1 polynomial \n");
printf("2 : create 2 polynomial\n");
printf("3 : display\n");
printf("4 : Add polynomials\n");
printf("5 : Multiply polynomials\n");
printf("6 : Quit\n");
printf("Enter your choice :\n");
scanf("%d",&option);
switch(option)
{
case 1:h1=init();read(h1);break;
case 2:h2=init();read(h2);break;
case 3:printf("\n1 polynomial -> \n");
      print(h1);
      printf("\n2 polynomial -> \n");
      print(h2);
      break;
case 4:h3=add(h1,h2);
      printf("\n1 polynomial -> \n");
      print(h1);
      printf("\n2 polynomial -> \n");
      print(h2);
      printf("\nSum = \n");
      print(h3);
      break;
case 5:h3=multiply(h1,h2);
      printf("\n1 polynomial -> \n");
      print(h1);
      printf("\n2 polynomial -> \n");
      print(h2);
      printf("\nProduct = \n");
      print(h3);
      break;
}
}while(option!=6);
getch();
}

void  read(node *h)
{
int n,i,j,power,coeff;
node *p;
p=init();
printf("Enter number of terms :\n");
scanf("%d",&n);
/* read n terms */
for (i=0;i<n;i++)
{ printf("enter a term(power  coeff.)\n");
scanf("%d%d",&power,&coeff);
for(p=h,j=0;j<power;j++)
   p=p->next;
p->coeff=coeff;
}
}
void print(node *p)
{
/* while(p!=NULL)

{  int i;
   printf("%dX^%d   ",p->coeff,i);
   p=p->next;
   if(p!=NULL)
    printf("+");
   }*/
   int i;
for(i=0;p!=NULL;i++,p=p->next)
{
if(p->coeff!=0)

printf("%dX^%d   ",p->coeff,i);
     if(p->coeff+1!=0)
    printf("+");
}
  }
node * add(node *h1, node *h2)
{
    node *h3,*p;
    h3=init();
    p=h3;
    while(h1!=NULL)
     {
h3->coeff=h1->coeff+h2->coeff;
h1=h1->next;
h2=h2->next;
h3=h3->next;
     }
 return(p);
}
node * multiply(node *h1, node *h2)
{
node *h3,*p,*q,*r;
int i,j,k,coeff,power;
h3=init();
for(p=h1,i=0;p!=NULL;p=p->next,i++)
{
for(q=h2,j=0;q!=NULL;q=q->next,j++)
   {
coeff=p->coeff * q->coeff;
power=i+j;
for(r=h3,k=0;k<power;k++)
r=r->next;
r->coeff=r->coeff+coeff;
    }
  //return(h3);
}
return(h3);
}
node * init()
{
    int i;
    node *h=NULL,*p;
    for(i=0;i<MAX;i++)
{
p=(node*)malloc(sizeof(node));
p->next=h;
p->coeff=0;
h=p;
}
  return(h);
}