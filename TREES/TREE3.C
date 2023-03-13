#include<stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct tree
{
	int data;
	struct tree *left,*right;
}tree;

tree *stack[MAX];
int top=-1;
tree *copy_root=NULL;



tree *insert(tree *root, int ikey);
void preorder(tree *root);
void postorder(tree *root);
void inorder(tree *root);
void copytree(tree *root);
void preorder1(tree *copy_root);
//stack implementaton functions
void push_stack(tree *);
tree *pop_stack();
int stack_empty();


int main()
{
	tree *root=NULL;
	int choice,key;
	//create();
	do{
	printf("\nEnter your choice :\n1.Insert node\n2.Preorder traversal\n3.Postorder traversal\n4.Inorder traversal\n5.Copy a tree\n6.Preorder of copied tree\n7.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter data : ");
			scanf("%d",&key);
			root=insert(root,key);
			break;
	    case 2:
	    	preorder(root);
	    	break;
	    case 3:
	    	postorder(root);
	    	break;
	    case 4:
	    	inorder(root);
	    	break;
	    case 5:
	    	copytree(root);
	    	break;
	    case 6:
	    	preorder1(copy_root);
	    	break;
	    default:
	    	printf("\nInvalid input...!");
	}
    }while(choice!=7);
    //printf("\n%d",root->data);
    return 0;
}
	
tree *insert(tree *root, int ikey)
{
        tree *tmp,*par,*ptr;

        ptr = root;
        par = NULL;

        while( ptr!=NULL)
        {
                par = ptr;
                if(ikey < ptr->data)
                        ptr = ptr->left;
                else if( ikey > ptr->data )
                        ptr = ptr->right;
                else
                {
                        printf("\nDuplicate key");
                        return root;
                }
        }

        tmp=(tree *)malloc(sizeof(tree));
        tmp->data=ikey;
        tmp->left=NULL;
        tmp->right=NULL;

        if(par==NULL)
                root=tmp;
        else if( ikey < par->data )
                par->left=tmp;
        else
                par->right=tmp;

        return root;
}

void preorder(tree *root)
{
        tree *ptr = root;
        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        push_stack(ptr);
        while( !stack_empty() )
        {
                ptr = pop_stack();
                printf("%d  ",ptr->data);
                if(ptr->right!=NULL)
                        push_stack(ptr->right);
                if(ptr->left!=NULL)
                        push_stack(ptr->left);
        }
       printf("\n");
}

void postorder(tree *root)
{
        tree *ptr = root;
        tree *q;

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

void inorder(tree *root)
{
        tree *ptr=root;

        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        while(1)
        {
      while(ptr->left!=NULL )
                {
                        push_stack(ptr);
                        ptr = ptr->left;
                }

                while( ptr->right==NULL )
                {
                        printf("%d  ",ptr->data);
                        if(stack_empty())
                                return;
                        ptr = pop_stack();
                }
                printf("%d  ",ptr->data);
                ptr = ptr->right;
        }
        printf("\n");
}

void copytree(tree *root)
{
	copy_root=root;
	tree *q,*p,*ptr;
	p=q=ptr=copy_root;
	push_stack(ptr);
	while(!stack_empty())
	{
		ptr = pop_stack();
        if(copy_root->data>=ptr->data)
		{
        	if(ptr->data<p->data)
        	{
        		q=p;
        		p->left=ptr;
        		p=p->left;
			}
			else if(ptr->data>p->data)
			{
				q->right=ptr;
			}
        	if(ptr->right!=NULL)
        	push_stack(ptr->right);
        	if(ptr->left!=NULL)
        	push_stack(ptr->left);
        }
        else
        {
        	p=q=ptr;
        	copy_root->right=ptr;
        	push_stack(ptr);
        	while(!stack_empty())
			{
				ptr = pop_stack();
        		
        			if(ptr->data<p->data)
        			{
        				q=p;
        				p->left=ptr;
        				p=p->left;
					}
					else if(ptr->data>p->data)
					{
						q->right=ptr;
					}
        			if(ptr->right!=NULL)
        			push_stack(ptr->right);
        			if(ptr->left!=NULL)
        			push_stack(ptr->left);
			}
		}
	}
	printf("%d",copy_root->data);
}

void preorder1(tree *copy_root)
{
        tree *ptr = copy_root;
        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        push_stack(ptr);
        while( !stack_empty() )
        {
                ptr = pop_stack();
                printf("%d  ",ptr->data);
                if(ptr->right!=NULL)
                        push_stack(ptr->right);
                if(ptr->left!=NULL)
                        push_stack(ptr->left);
        }
        printf("\n");
}


void push_stack(tree *item)
{
        if(top==(MAX-1))
        {
                printf("Stack Overflow\n");
                return;
        }
        top=top+1;
        stack[top]=item;
}

tree *pop_stack()
{
        tree *item;
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