#include<stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root;
struct tree *current;
struct tree *data;

struct tree *createNode()
{
    int data;
    struct tree *temp = NULL;
    printf("\nEnter Data : ");
    scanf("%d",&data);
    temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;

}

void createTree()
{
    int n,flag,choice,ch=0;
    current = createNode();
    root = current;
    do
    {
        flag = 0;
        while(flag != 1)
        {
            printf("\nEnter Value In Left Or Right w.r.t : %d\n",current->data);
            printf("\nEnter\n1.For Left\n2.For Right\nEnter Your Choice : ");
            scanf("%d",&n);
            ch++;
            if(n == 1)
            {
                if(current->left == NULL)
                {
                    current->left = createNode();
                    flag = 1;
                }
                else
                    current = current->left;
            }
            else
            {
                if(current->right == NULL)
                {
                    current->right = createNode();
                    flag = 1;
                }
                else
                    current = current->right;
            }
        }
        current=root;
        printf("\nDo You Want To Continue ?\n1.Yes\n2.No\nEnter Your Choice : ");
        scanf("%d",&choice);
    }while(choice == 1);
}

void preOrder(struct tree *node)
{
    struct tree *stk[100];
    int top = -1;
    struct tree *curr = NULL;
    curr = node;
    do
    {
        while(curr != NULL)
        {
            printf(" %d\n",curr->data);
            if(curr->right != NULL)
            {
                stk[++top] = curr->right;
            }
            curr = curr->left;
        }
        curr = stk[top--];
    }while(top >= -1 && curr != NULL);
}

void mirrorTree(struct tree *node)
{
    struct tree *queue[100];
    int front = 0,rear = -1,count = 0;
    if (node==NULL)
        return;

    queue[++rear] = node;
    count++;
    while(count != 0)
    {
        struct tree *curr = queue[front++];
        count--;

        struct tree *temp = curr->right;
        curr->right = curr->left;
        curr->left = temp;

        if(curr->left != NULL)
        {
            queue[++rear] = curr->left;
            count++;
        }
        if(curr->right != NULL)
        {
            queue[++rear] = curr->right;
            count++;
        }
    }
}

int heightTree(struct tree *node)
{
    struct tree *queue[100];
    struct tree *temp = NULL;
    int front=0,rear=-1,count = 0,height = 0;
    if (node==NULL)
        return 0;
    else
    {
        queue[++rear] = node;
        count++;
        while(1)
        {
            int nodeCount = count;
            if(nodeCount == 0)
                return height;
            height++;
            while(nodeCount > 0)
            {
                temp = queue[front++];
                count--;

                if(temp->left != NULL)
                {
                    queue[++rear] = temp->left;
                    count++;
                }
                if(temp->right != NULL)
                {
                    queue[++rear] = temp->right;
                    count++;
                }
                nodeCount--;
           }
       }
   }
}


int main()
{
    printf("\nCreating The Binary Tree :\n");
    createTree();
    int choice,height,n = 0;
    do
    {
        printf("\nEnter \n1 To Perform Pre-Order Traversing\n2 To Display Mirror Tree\n3 To Display Height Of Tree\n4 To Exit\n\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                preOrder(root);
                break;
            case 2:
                mirrorTree(root);
                preOrder(root);
                break;
            case 3:
                height = heightTree(root);
                printf("\nThe Height Of Tree Is : %d\n",height);
                break;
            case 4:
                n++;
            default:
                printf("Wrong Input Try Again");
        }

    }while(n != 1);
    return 0;
}