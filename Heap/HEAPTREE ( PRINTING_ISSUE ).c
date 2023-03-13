#include <stdio.h>
#include <stdlib.h>

int counter = 0;

typedef struct node n;
struct node
{
   int data;
   struct node *left;
   struct node *right;
};

n *root = NULL;

void insertnode(int data)
{
    int i = 0;
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    n *temp = root;
    n *temp2 = root;
    if(root == NULL)
    {
        root = NewNode;
    }
    else
    {
        jump:
            i++;
            if(temp->left == NULL)
                temp->left = NewNode;
            else if(temp->right == NULL)
                temp->right = NewNode;
            else if(i == 1)
            {
                jump2:
                    while(i>0)
                    {
                        temp2 = temp;
                        temp = temp->left;
                        i--;
                    }
                    i++;
                    goto jump;
            }
            else if(i == 2)
            {
                temp = temp2->right;
                goto jump;
            }
            else if(i == 3 && temp2 == root)
            {
                temp = temp2->left;
                i = i-2;
                goto jump2;
            }
            else if(i == 3 && temp2 != root)
            {
                temp2 = root;
                temp = temp2->right;
                i = i-2;
                goto jump2;
            }
    }
}

typedef struct stack s;
struct stack
{
   struct node* stk;
   struct stack *next;
};

s *head = NULL;


void Push(n* data)
{
    s *NewNode = (s*) malloc(sizeof(s));
    NewNode->stk = data;
    s *temp = head;
    if(head==NULL)
    {
        NewNode->next = head;
        head = NewNode;
    }
    else
    {
        while(temp->next != NULL)
            temp=temp->next;//while loop goes to last element of list
        temp->next=NewNode;//last element now points to new node
        NewNode->next = NULL;//end pointer from new node as it is being added in the end
    }
}

n* Pop()
{
    if(head==NULL)
        printf("list is empty");
    else
    {
        n *copy;
        s *temp = head;//copy head in temp
        s *second = head;
        if(temp->next != NULL)
        {
            temp = temp->next;
            while(temp->next != NULL)
            {
                second = temp;
                temp = temp->next;
            }
            copy = temp->stk;
            free(temp);//free first element stored in temp
            second->next = NULL;
            return copy;
        }
        else
        {
            copy = temp->stk;
            return copy;
        }
    }
}

void printheap()
{
    n *temp = root;
    n *temp2 = root;
    int c = 0 , i1 = 0 , i2 = 0 , I = 0;
    c = counter;
    if(c == 0)
    {
        printf("Tree Empty!");
        return;
    }
    printf("\n\n");
    printf(" %d ",temp->data);
    c--;
    do
    {
        temp = root;
        temp2 = root;
        I++;
        i1 = I;
        i2 = I;
        while(i1 >= 3)
        {
            temp2 = temp2->left;
            i1--;
        }
        i1 = I;
        jump:
        while(i1 != 0 && temp->left != NULL)
        {
            Push(temp);
            temp = temp->left;
            i1--;
        }
        printf(" %d ",temp->data);
        c--;
        while(i2 != 0 && c != 0)
        {
            temp = Pop();
            if(temp == root)
            {
                i2 = I - 1;
                temp = temp->right;
                temp2 = root;
                i1 = I;
                while(i1 >= 3)
                {
                    temp2 = temp2->right;
                    i1--;
                }
                i1 = i2;
                goto jump;
            }
            if(temp == temp2)
            {
                temp = temp->right;
                i1 = i2;
                goto jump;
            }
            if(temp->right != NULL)
            {
                temp = temp->right;
                printf(" %d ",temp->data);
                c--;
                i2--;
            }
        }
    } while(c != 0);
}

void heapsort(int h)
{
    do
    {
        n *temp = root;
        int c = 0 , d = 0 , data = 0;
        c = counter;
        if(c == 0)
        {
            printf("Tree Empty!");
            return;
        }
        do
        {
            while(temp->left != NULL)
            {
                Push(temp);
                temp = temp->left;
            }
            if(temp->right != NULL)
            {
                Push(temp);
                temp = temp->right;
            }
            else
            {
                d = temp->data;
                while(c >= 0)
                {
                    temp = Pop();
                    if(c == 1 || c == 2)
                    {
                        temp = root;
                        goto jump;
                    }
                    if(temp->right != NULL && temp->right->data != d)
                    {
                        Push(temp);
                        temp = temp->right;
                        break;
                    }
                    else
                    {
                        jump:
                        if(temp->right == NULL)
                            goto jump2;
                        if(temp->data < temp->left->data || temp->data < temp->right->data)
                        {
                            if(temp->left->data > temp->right->data)
                            {
                                data = temp->left->data;
                                temp->left->data = temp->data;
                                temp->data = data;
                                d = data;
                            }
                            else if(temp->right->data > temp->left->data)
                            {
                                data = temp->right->data;
                                temp->right->data = temp->data;
                                temp->data = data;
                            }
                        }
                        jump2:
                        if(temp->left->data > temp->data)
                        {
                            data = temp->left->data;
                            temp->left->data = temp->data;
                            temp->data = data;
                            d = data;
                        }
                        c = c - 2;
                    }
                }
            }
        } while(c >= 0);
        h--;
    }while(h != 0);
}

void printlist()
{
    n *temp = root;
    printf(" %d ",temp->data);
    /*while(temp->right != NULL)
    {
        temp = temp->right;
        printf(" %d ",temp->data);
    }
    temp = root;*/
    while(temp->left != NULL)
    {
        temp = temp->left;
        printf(" %d ",temp->data);
    }
}

int main()
{
    int x=0;
    do
    {
        printf("\n1. Create Heap Tree\n2. Print Heap Tree\n3. Print Sorted Heap Tree\n4. Exit\n\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            {
                int i;
                int* arr;
                printf("\n\nEnter The Number of Elements : ");
                scanf("%d",&counter);
                arr = (int*)malloc(counter * sizeof(int));
                printf("Enter The Elements of Heap Tree : ");
                for(i=0;i<counter;i++)
                {
                    scanf("%d",&arr[i]);
                    insertnode(arr[i]);
                }
                break;
            }
        case 2:
            {
                printf("\n\nThe Given Heap Tree is : ");
                printheap();
                break;
            }
        case 3:
            {
                printf("\n\nThe Heap Tree in Descending Order is : ");
                int c = 0,i = 0,d = 1 , D = 0 , h = 0;
                c = counter;
                do
                {
                    i++;
                    while(i != 0)
                    {
                        d = d * 2;
                        i--;
                    }
                    D = c/d;
                    h++;
                }while(D >= 1);
                heapsort(h);
                printheap();
                break;
            }

        case 5:
        {
            printlist();
            break;
        }
        case 4:
            break;
        }
    }while(x != 4);
    return 0;
}



