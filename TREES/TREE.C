/*void preorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
printf("%d ->", rootNode->data);
preorder(rootNode->leftNode);
preorder(rootNode->rightNode);
}usinsg recursion

HEIGHT 
int height(tree* root)
{
    queue<tree*> q;
    int height = 0;
    int nodeCount = 0; 
    tree* current; 

    if (root == NULL) {
        return 0;
    }
    q.push(root);
    while (!q.empty())
    {
      
        height++;
       
 
        nodeCount = q.size();
        while (nodeCount--) {
            current = q.front();
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
            q.pop();
        }
    }
    return height;
}


mirror
mirrorify function takes two trees,
original tree and a mirror tree
It recurses on both the trees,
but when original tree recurses on left,
mirror tree recurses on right and
vice-versa
void mirrorify(node* root, node** mirror)
{
    if (root == NULL) {
        mirror = NULL;
        return;
    }
 
    // Create new mirror node from original tree node
    *mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}

/*void preOrderIterative(struct Node* root)
{
    if (root == NULL)
        return;

    struct Stack* stack = createStack(MAX_SIZE);
    do
    {
        while (root)
        {
            if (root->left)
                push(stack, root->left);
            push(stack, root);

            root = root->right;
        }

        root = pop(stack);

        if (root->right && peek(stack) == root->right)
        {
            pop(stack);
            push(stack, root);
            root = root->right;

        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}

*/

#include <stdio.h>
#define MAX_SIZE 100

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Stack
{
    int size;
    int top;
    struct Node* *array;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node*) malloc(stack->size * sizeof(struct Node));
    return stack;
}

int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }

int isEmpty(struct Stack* stack)
{ return stack->top == -1; }

void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct Node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}



void preorder(struct node* root)
{
        struct node *ptr = root;
        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        push(ptr);
        while( !stack_empty() )
        {
                ptr = pop();
                printf("%d  ",ptr->data);
                if(ptr->right!=NULL)
                        push(ptr->right);
                if(ptr->left!=NULL)
                        push(ptr->left);
        }
      printf("\n");
}

void mirrorimage(struct node* root)
{
  if (root != NULL)
    {
        struct node* temp;
        /*first traversing the left subtree */
        mirrorimage(root->left);      
        /* Traversing the right subtree. */
        mirrorimage(root->right);     
 
        /* swap the left and right child of all the nodes to create
         * a mirror image of a tree
         */
 
        temp = root->left;
        root->left  = root->right;   
        root->right = temp;
 
    }
}
 
/*
 * Function to find the height of a tree.
 */
 
int heightoftree(struct node* root)
{
    int max;
 
    if (root!=NULL)
    {
        /*Finding the height of left subtree.*/
        int leftsubtree = heightoftree(root->left);
 
        /*Finding the height of right subtree.*/
        int rightsubtree = heightoftree(root->right);  
 
 
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
 
/*
 * Function to print all the nodes left to right of the current level
 */
 
void currentlevel(struct node* root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->info);
        }
 
        else if (level > 1)
        {
            currentlevel(root->left, level-1);
            currentlevel(root->right, level-1);
        }
    }
 
}

int main()
{

    struct Node* root  , * new , *p ;
    root = NULL;
    char ch,ch2;
    int key;
    int i,n,x;
    printf("Enter the data:");
    scanf("%d",&key);
    new = newNode(key);
       
    /*p = root;
    printf("do you want to add this data then type Y or if you want to stop type N")
    ch2 = getchar();*/

    if(root == NULL && (ch2 == "Y" || ch2 == "y"))
    {root = new;
    printf("element added to form root");}    
    else
    {
     p = root;
     do
     {
     printf(" where do you want to add with respect to %d", p->data);
     printf(" enter L for left and R for right ");
     ch = getchar();
     if(ch == 'L' || ch == 'l')
     {
      if( p->left == NULL)
      {  
       P->left == new;
      }
      else
     {p = p->left;}
     }
    
     else if(ch == 'R' || ch == 'r')
     {
      if( p->right == NULL)
      {  
       P->right == new;
      }
      else
     {p = p->right;}
     }
     
    }while(p!=NULL && (ch2 == "Y" || ch2 == "y"))




    printf(" what do you want to do with the tree /n");
    printf(" press 1 for preordder presentation  
    printf("Pre order traversal of binary tree is :\n");
    printf("[");
    pretOrderIterative(root);
    printf("]");


    return 0;
}