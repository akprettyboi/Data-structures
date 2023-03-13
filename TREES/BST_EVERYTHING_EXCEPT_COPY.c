/******************************************************************************

                            MAX HEAP DESCENDING ORDER

*******************************************************************************/

 #include<stdio.h>
#include <stdlib.h>
#define MAX 30

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root;
struct tree *current;
struct tree *data;

struct tree *stack[MAX];
int top = -1;

void createBST()
{
    int data;
    printf("\nEnter Data : ");
    scanf("%d", &data);
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = data;
    temp->left = temp->right = NULL;
    root = temp;

    while (1) {
        printf("\nEnter Data : ");
        scanf("%d", &data);
        if (data == -1) break;
        insertNode(data);
    }
}

void insertNode(int data)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = data;
    temp->left = temp->right = NULL;

    struct tree *current = root;
    struct tree *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (parent == NULL) {
        root = temp;
    } else if (data < parent->data) {
        parent->left = temp;
    } else {
        parent->right = temp;
    }
}


	
void inOrder(struct tree *node) {
    struct tree *current = node;
    struct tree *stack[MAX];
    int top = -1;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void postOrder(struct tree *node) {
    struct tree *current = node;
    struct tree *stack1[MAX];
    struct tree *stack2[MAX];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = current;
    while (top1 != -1) {
        current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
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

void levelOrder(struct tree *node) {
    if (root == NULL) {
        return;
    }
    struct tree *queue[MAX];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while (front <= rear) {
        struct tree *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
}


/*{
        struct tree *ptr = node;
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
          printf("\n");
        }
      
}*/



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


int countLeafNodes(struct tree *root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    struct tree *queue[MAX];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while (front <= rear) {
        struct tree *current = queue[front++];
        if (current->left == NULL && current->right == NULL) {
            count++;
        }
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
    return count;
}

/*void push_stack(struct tree *item)
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
}*/


int main()
{
    printf("\nCreating The Binary Tree :\n");
    createBST();
    int choice,height,count,n = 0;
    do
    {
        printf("\nEnter \n1 To Perform Pre-Order Traversing\n2 To Display Mirror Tree in preorder traversing\n3 To Display Height Of Tree\n4 To perform Postorder traversing\n5 To perform inorder traversing\n6 To perform level wise traversing\n7 To display no of leaf nodes\n8 To Exit\n\nEnter Your Choice : ");
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
                postOrder(root);
                break;
            case 5:
                inOrder(root);
                break;
            case 6:
                levelOrder(root);
                break;
            case 7:
                count = countLeafNodes(root);
                printf("\nThe Leafnodes  Of Tree Is : %d\n",count);
                break;
            case 8:
                n++;
                break;
            default:
                printf("Wrong Input Try Again");
        }

    }while(n != 1);
    return 0;
}


