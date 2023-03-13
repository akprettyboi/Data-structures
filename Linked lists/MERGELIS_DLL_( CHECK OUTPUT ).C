#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
struct node *prev;
int data;
struct node *next;
}list;
void acp_list(list ** node)
{
int flag,i=0; 
int data;
list * tmp_node;
tmp_node = (list *) malloc(sizeof(list)); //create the first node
*node = tmp_node; //Store the head address to the reference variable
tmp_node->prev = NULL;
do
{
i++;
//Get the user data
printf("\nEnter List's %d Element :",i);
scanf("%d", &data);

tmp_node->data = data;
//Done storing user data
tmp_node->next = NULL;
//Now increase the Linked on user condition
//Ask user for continuation
printf("\nContinue adding more terms to the list?\n1 - To continue adding \n0 - To complete the List :\n ");
scanf("%d", &flag);
//printf("\nFLAG: %c\n", flag);
//Grow the linked list on condition
if(flag)
{
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
} while (flag);
}
void sort(list ** result, list * list1, list * list2)
{
int flag;
list * tmp_node;
tmp_node = (list *) malloc(sizeof(list)); //create the first node
*result = tmp_node; //Store the head address to the reference variable
tmp_node->prev = NULL;
while(list1 && list2)
{
if(list1->data > list2->data)
{
tmp_node->data = list2->data;
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
tmp_node->data = list1->data;
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
else if(list2->data > list1->data)
{
tmp_node->data = list1->data;
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
tmp_node->data = list2->data;
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
else if(list2->data == list1->data)
{
tmp_node->data = list2->data;
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
tmp_node->data = list1->data;
tmp_node->next = (list *) malloc(sizeof(list)); //Grow the list
tmp_node->prev=tmp_node->next;
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
list1=list1->next;
list2=list2->next;
}
}
void disp(list * dlist)
{
while(dlist != NULL)
{
printf("%d\t", dlist->data);
dlist = dlist->next;
}
}
void main()
{
list * list1,* list2,* list3;
clrscr();
printf("\nEnter 1st List in Sorted form):\n");
acp_list(&list1);
printf("\nShowcasing of the 1st List:\n");
disp(list1);
printf("\nEnter 2st Listin Sorted form):\n");
acp_list(&list2);
printf("\nShowcasing of the 2st List:\n");
disp(list2);
printf("\n\nSORTING LIST IF NOT SORTED AFTER COMBINING:\n.\n.\n.\n.");
sort(&list3,list1,list2);
printf("\nShowing FINAL RESULT:\n");
disp(list3);
getch();
}