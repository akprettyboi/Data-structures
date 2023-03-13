#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true} boolean;

struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node *insert(struct node *root, int ikey);
struct node *del(struct node *root, int dkey);
struct node *case_a(struct node *root, struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root, struct node *par,struct node *ptr);

void inorder( struct node *root);
void preorder( struct node *root);

struct node
{
        struct node *left;
        boolean lthread;
        int info;
        boolean rthread;
        struct node *right;
};

int main( )
{
        int choice,num;
        struct node *root=NULL;

        while(1)
        {
                printf("\n");
                printf("1.Insert\n");
                printf("2.Delete\n");
                printf("3.Inorder Traversal\n");
                printf("4.Preorder Traversal\n");
                printf("5.Postorder Traversal\n");
                printf("6.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                 case 1:
                        printf("\nEnter the number to be inserted : ");
                        scanf("%d",&num);
                        root = insert(root,num);
                        break;

                 case 2:
                        printf("\nEnter the number to be deleted : ");
                        scanf("%d",&num);
                        root = del(root,num);
                        break;

                 case 3:
                        inorder(root);
                        break;

                 case 4:
                        preorder(root);
                        break;
               
                 
                 case 5:
                        postorder(root);
                        break;

                 

                 

                  case 6:
                         exit(1);

                 default:
                        printf("\nWrong choice\n");
                }/*End of switch */
        }/*End of while */

        return 0;

}/*End of main( )*/

struct node *insert(struct node *root, int ikey)
{
        struct node *tmp,*par,*ptr;

        int found=0;

        ptr = root;
        par = NULL;

        while( ptr!=NULL )
        {
                if( ikey == ptr->info)
                {
                        found =1;
                        break;
                }
                par = ptr;
                if(ikey < ptr->info)
                {
                        if(ptr->lthread == false)
                                ptr = ptr->left;
                        else
                                break;
                }
                else
                {
                        if(ptr->rthread == false)
                                ptr = ptr->right;
                        else
                                break;
                }
        }

        if(found)
                printf("\nDuplicate key");
        else
        {

                tmp=(struct node *)malloc(sizeof(struct node));
                tmp->info=ikey;
                tmp->lthread = true;
                tmp->rthread = true;
                if(par==NULL)
                {
                        root=tmp;
                        tmp->left=NULL;
                        tmp->right=NULL;
                }
                else if( ikey < par->info )
                {
                        tmp->left=par->left;
                        tmp->right=par;
                        par->lthread=false;
                        par->left=tmp;
                }
                else
                {
                        tmp->left=par;
                        tmp->right=par->right;
                        par->rthread=false;
                        par->right=tmp;
                }
        }
        return root;
}/*End of insert( )*/

struct node *del(struct node *root, int dkey)
{
        struct node *par,*ptr;

        int found=0;

        ptr = root;
        par = NULL;

        while( ptr!=NULL)
        {
                if( dkey == ptr->info)
                {
                        found =1;
                        break;
                }
                par = ptr;
                if(dkey < ptr->info)
                {
                        if(ptr->lthread == false)
                                ptr = ptr->left;
                        else
                                break;
                }
                else
                {
                        if(ptr->rthread == false)
                                ptr = ptr->right;
                        else
                                break;
                }
        }

        if(found==0)
                printf("\ndkey not present in tree");
        else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
                root = case_c(root,par,ptr);
        else if(ptr->lthread==false )/*only left child*/
        root = case_b(root, par,ptr);
        else if(ptr->rthread==false)/*only right child*/
        root = case_b(root, par,ptr);
        else /*no child*/
                root = case_a(root,par,ptr);
        return root;
}/*End of del( )*/

struct node *case_a(struct node *root, struct node *par,struct node *ptr )
{
        if(par==NULL) /*root node to be deleted*/
                root=NULL;
        else if(ptr==par->left)
        {
                par->lthread=true;
                par->left=ptr->left;
        }
        else
        {
                par->rthread=true;
                par->right=ptr->right;
        }
        free(ptr);
        return root;
}/*End of case_a( )*/

struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
        struct node *child,*s,*p;

        /*Initialize child*/
        if(ptr->lthread==false) /*node to be deleted has left child */
                child=ptr->left;
        else                /*node to be deleted has right child */
                child=ptr->right;


        if(par==NULL )   /*node to be deleted is root node*/
                root=child;
        else if( ptr==par->left) /*node is left child of its parent*/
                par->left=child;
        else                     /*node is right child of its parent*/
                par->right=child;

        s=in_succ(ptr);
        p=in_pred(ptr);

        if(ptr->lthread==false) /*if ptr has left subtree */
                        p->right=s;
        else
        {
                if(ptr->rthread==false) /*if ptr has right subtree*/
                        s->left=p;
        }

        free(ptr);
        return root;
}/*End of case_b( )*/

struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
        struct node *succ,*parsucc;

        /*Find inorder successor and its parent*/
        parsucc = ptr;
        succ = ptr->right;
        while(succ->left!=NULL)
        {
                parsucc = succ;
                succ = succ->left;
        }

        ptr->info = succ->info;

        if(succ->lthread==true && succ->rthread==true)
                root = case_a(root, parsucc,succ);
        else
                root = case_b(root, parsucc,succ);
        return root;
}/*End of case_c( )*/

struct node *in_succ(struct node *ptr)
{
        if(ptr->rthread==true)
                return ptr->right;
        else
        {
                ptr=ptr->right;
                while(ptr->lthread==false)
                        ptr=ptr->left;
                return ptr;
        }
}/*End of in_succ( )*/

struct node *in_pred(struct node *ptr)
{
        if(ptr->lthread==true)
                return ptr->left;
        else
        {
                ptr=ptr->left;
                while(ptr->rthread==false)
                        ptr=ptr->right;
                return ptr;
        }
}/*End of in_pred( )*/

void inorder( struct node *root)
{
        struct node *ptr;
        if(root == NULL )
        {
                printf("Tree is empty");
                return;
        }

        ptr=root;
        /*Find the leftmost node */
        while(ptr->lthread==false)
                ptr=ptr->left;

        while( ptr!=NULL )
        {
                printf("%d ",ptr->info);
                ptr=in_succ(ptr);
        }
}/*End of inorder( )*/

void preorder(struct node *root )
{
        struct node *ptr;
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        ptr=root;

        while(ptr!=NULL)
        {
                printf("%d ",ptr->info);
                if(ptr->lthread==false)
                        ptr=ptr->left;
                else if(ptr->rthread==false)
                        ptr=ptr->right;
                else
                {
                        while(ptr!=NULL && ptr->rthread==true)
                                ptr=ptr->right;
                        if(ptr!=NULL)
                                ptr=ptr->right;
                }
        }
}/*End of preorder( )*/ 

int nod = 0;
int Arr[50];
void add(int key)
{
    Arr[nod] = key;
    nod++;
}
void reverse_Array()
{
    for(int i = nod-1; i >=0; i--)
    {
        printf("%d ", Arr[i]);
    }
}
void postorder(struct node *root)
{
    struct node *P;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    P = root;
    while (P != NULL)
    {
        if (P->rthread == false)
            P = P->right;
        else if (P->lthread == false)
            P = P->left;
        else
        {
            printf("%d ", P->info);
            while (P != NULL && P->lthread == true)
                P = P->left;
            if (P != NULL)
                P = P->left;
        }
    }
}
/*end of postorder*/

/* void postorder(struct node *root)
{
    struct node *current = root;

    // Move to the leftmost node
    while (current != NULL && current->lthread == false)
        current = current->left;

    // Traverse the tree
    while (current != NULL)
    {
        printf("%d ", current->info); // Print the node value

        // If the current node has a right child, move to the leftmost node in the right subtree
        if (current->rthread == false)
        {
            current = current->right;
            while (current != NULL && current->lthread == false)
                current = current->left;
        }
        // Otherwise, move up to the parent node
        else
        {
            struct node *previous = current;
            current = in_pred(current);

            // If the current node is the right child of the previous node, we've already visited the left subtree, so we need to move up again
            if (current != NULL && current->right == previous)
            {
                previous = current;
                current = in_pred(current);
            }
        }
    }
}
*/

/*
void postorder(struct node *root )
{
        struct node *P;
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        P=root;
        while(P!=NULL)
        {
            add(P->data);
            
            if(P->Rth==false) 
                P=P->Right;
            
            else if(P->Lth==false) 
                P=P->Left;
            
            else 
            {
                while(P!=NULL && P->Lth==true) 
                    P=P->Left;
                
                if(P!=NULL)
                    P=P->Left;
            }
        }
        reverse_Array();
}end of postorder*/
