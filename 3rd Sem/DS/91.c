

#include <stdio.h>
#include <stdlib.h>

int min = 1000;
int k;

struct Node
{
    int data;
    struct Node *left, *right;
};
void search(struct Node* temp,int del)
{
    if (temp != NULL)
    {
        search(temp->left,del);
        if(del==temp->data)
        k=1;
        search(temp->right,del);
    }
}
void maketree(struct Node *root, int item)
{
    root->data = item;
    root->left = root->right = NULL;
}

void bst( struct Node *root , int num )
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    
        if(root->data > num)
        {
            if(root->left == NULL)
            {
                temp->right = NULL;
                temp->left = NULL;
                temp->data = num;
                root->left = temp;
            }
            else
            bst(root->left, num);
            
        }
        else if(root->data <= num)
        {
           if(root->right == NULL)
            {
                temp->right = NULL;
                temp->left = NULL;
                temp->data = num;
                root->right = temp;
            }
            else
            bst(root->right, num); 
        }
}


void inorder(struct Node* temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d - ", temp->data);
        inorder(temp->right);
    }
}

struct Node* mins(struct Node* temp)
{
    
    struct Node* cur = temp;
    while(cur&&cur->left!=NULL)
    cur = cur->left;
    return cur;
    
}

struct Node* bstdel(struct Node *root , int del)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    int val;
    if(root)
    {
        if(root->data > del)
        {
            root->left = bstdel(root->left , del);
        }
        else if(root->data < del)
        {
            root->right = bstdel(root->right , del);
        }
        else
        {
            if(root->left == NULL && root ->right == NULL)
            {
               return NULL;
            }
            else if(root->left == NULL)
            {
                
                temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                temp = mins(root->right);
                root->data = temp ->data;
                root->right = bstdel(root->right,temp->data);
            }
            
        }
        return root;
    }
    else
    return root;
}


int main()
{
    int del[20];
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    int n;
    int num;
    int a[20];
    printf("Enter Number of elements in array : ");
    scanf("%d",&n);
    int i;
    printf("Enter Array Elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    maketree(root,a[0]);
    for(i=1;i<n;i++)
    {
        k=0;
        search(root,del[i]);
        if(k==0)
        bst(root,a[i]);
        k=0;
    }
    inorder(root);
    printf("\nEnter Number of elements you wish to delete : ");
    scanf("%d",&n);
    printf("Enter elements to be deleted :\n");
    for(i=0;i<n;i++)
    scanf("%d",&del[i]);
    for(i=0;i<n;i++)
    {
        k=0;
        search(root,del[i]);
        while(k)
        {
            root = bstdel(root,del[i]);
            k=0;
            search(root,del[i]);
        }
        inorder(root);
        printf("\n");
    }
    
}