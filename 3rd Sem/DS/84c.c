// C implementation to find height of a given Binary tree
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Function to get the count height in a binary tree*/
int HeightCount(struct node *node)
{
    int x=0,y=0;
    if (node == 0)
        return -1;
    x = HeightCount(node->left);
    y = HeightCount(node->right);
    if (x > y)
        return x+1;
    else
        return y+1;
}

/* allocates a new node with the
given data and NULL left and right pointers. */
struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


int main()
{
    /*create a tree*/
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    /*Height of the above created tree*/
    printf("Height of the tree is %d", HeightCount(root));

    return 0;
}
