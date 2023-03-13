#include<stdio.h>
#include<stdlib.h>
#define size 30

struct tree 
{
	int data;
	struct tree *left,*right;
};

struct tree *root=NULL;


//int flag=0;
int rear=-1;
int front=-1;
struct tree *queue[size];

struct tree *pop_stack();
int stack_empty();
struct tree *stack[size];
int top=-1;
void push_stack(struct tree *item);
struct tree *pop_stack();

//functions
void insert();
void postorder(struct tree *root);
void levelwise(struct tree *);
void leafnode(struct tree *);
void create();
void addq(struct tree *);
struct tree *delq();
int q_empty();

int main()
{
	int choice;
	create();
	do
	{
		printf("Enter your choice :");
		printf("\n1.Insert node\n2.Postorder traversal\n3.Display a tree levelwise\n4.Display leaf nodes of a tree\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				postorder(root);
				break;
			case 3:
				levelwise(root);
				break;
			case 4:
				leafnode(root);
				break;
			default:
				printf("\nInvalid input...!");
		}
		
	}while(choice!=5);
	
}

void create()
{
	struct tree *newNode=malloc(sizeof(struct tree));
	printf("\nEnter the data of root : ");
	scanf("%d",&newNode->data);
	root=newNode;
	root->left=NULL;
	root->right=NULL;
	//printf("%d",root->data);
}

void insert()
{
	int opt,flag;
	struct tree *p=root;
	struct tree *newNode=malloc(sizeof(struct tree));
	printf("\nEnter the data of node : ");
	scanf("%d",&newNode->data);
     do 
      {  flag = 0
	while(flag!=1)
	{
		if(flag==1)
		p=root;
		printf("\nWhere to add w.r.t %d ...(0 for left and 1 for right ) : ",p->data);
		scanf("%d",&opt);
		if(opt==0)
		{
			if(p->left==NULL)
			{
				//printf("%d",newNode->data);
				p->left=newNode;
				flag =1;
			}
			else
			{
				p=p->left;
				flag=0;
			}
		}
		else 
		{
			if(p->right==NULL)
			{
				p->right=newNode;
				flag =1;
			}
			else
			{
				p=p->right;
				flag=0;
			}
		}
		
	}
	root = p;
        printf("\nDo You Want To Continue ?\n1.Yes\n2.No\nEnter Your Choice : ");
        scanf("%d",&choice);
     }while(choice == 1);
}
	

void levelwise(struct tree *p)
{
	printf("%d",p->data);
	do
	{
		if(p->left!=NULL)
		addq(p->left);
		if(p->right!=NULL)
		addq(p->right);
		p=delq();
		printf("%d",p->data);
	}while(!q_empty() && p!=NULL);
}

void leafnode(struct tree *p)
{
	do
	{
		if(p->left!=NULL)
		addq(p->left);
		if(p->right!=NULL)
		addq(p->right);
		p=delq();
		if(p->left==NULL && p->right==NULL)
		printf("%d",p->data);
	}while(!q_empty() && p!=NULL);
}

void addq(struct tree *ch)
{
	if(rear==size-1)
	printf("\nStack overflow");
	else
	{
		if(front==-1)
		front=0;
		rear++;
		queue[rear]=ch;
	}
}

struct tree* delq()
{
	struct tree *n;
	if(q_empty())
	{
		printf("\nQueue underflow");
		//return;
    }
	else{
	n=queue[front];
	front++;
	return n;
	}
}

int q_empty()
{
	if(front==-1)
	return 1;
	else
	return 0;
}

void push_stack(struct tree *item)
{
        if(top==(size-1))
        {
                printf("Stack Overflow\n");
                //return;
        }
        top=top+1;
        stack[top]=item;
}

struct tree *pop_stack()
{
        struct tree *item;
        if(top==-1)
        {
                printf("Stack Underflow....\n");
                exit(1);
        }
        item=stack[top];
        top=top-1;
        return item;
}

int stack_empty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}

void postorder(struct tree *root)
{
        struct tree *ptr = root;
        struct tree *q;

        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        q = root;
        while(1)
        {
                while(ptr->left!=NULL)
                {
                        push_stack(ptr);
                        ptr=ptr->left;
                }

                while( ptr->right==NULL || ptr->right==q )
                {
                        printf("%d  ",ptr->data);
                        q = ptr;
                        if( stack_empty() )
                                return;
                        ptr = pop_stack();
                }
                push_stack(ptr);
                ptr = ptr->right;
        }
        printf("\n");
}