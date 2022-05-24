#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true} boolean;
struct node *insert(struct node *root, int ikey);

struct node
{
        struct node *left;
        boolean lthread;
        int info;
        boolean rthread;
        struct node *right;
};

struct node *inordersuccessor(struct node *ptr)
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
}

void inorder(struct node *root)
{
        struct node *ptr;
        if(root==NULL )
        {
            printf("Empty Tree!");
            return;
        }
        ptr=root;
        while(ptr->lthread==false)
            ptr=ptr->left;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=inordersuccessor(ptr);
        }
}

void preorder(struct node *root)
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
}
struct node *insert(struct node *root, int key)
{
    struct node *temp,*parent,*ptr;
    int found=0;
    ptr=root;
    parent=NULL;

    while(ptr!=NULL)
    {
        if(key==ptr->info)
        {
            found=1;
            break;
        }
        parent=ptr;
        if(key<ptr->info)
        {
            if(ptr->lthread==false)
                ptr=ptr->left;
            else
                break;
        }
        else
        {
            if(ptr->rthread==false)
                ptr=ptr->right;
            else
                break;
        }
    }

        if(found)
                printf("\nDuplicate key");
        else
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->info=key;
            temp->lthread=true;
            temp->rthread=true;
            if(parent==NULL)
            {
                root=temp;
                temp->left=NULL;
                temp->right=NULL;
            }
            else if(key<parent->info)
            {
                temp->left=parent->left;
                temp->right=parent;
                parent->lthread=false;
                parent->left=temp;
            }
            else
            {
                temp->left=parent;
                temp->right=parent->right;
                parent->rthread=false;
                parent->right=temp;
            }
        }
        return root;
}


int main( )
{
        int choice,num,n,a[100];
        struct node *root=NULL;
        printf("\nEnter number of nodes ");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            printf("\nEnter element - ");
            scanf("%d",&a[i]);
            root=insert(root,a[i]);
        }
        printf("\nConstructed Right In Threaded Binary Tree has the following data - \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\nInorder Traversal is \n");
        inorder(root);
        printf("\nPreorder Traversal is \n");
        preorder(root);
}