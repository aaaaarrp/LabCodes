// C implementation to find sum of elements of a given Binary tree
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

/* Function to get the count sum of nodes in a binary tree*/
int SumOfAllElements(struct node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return node->data;
    else
        return SumOfAllElements(node->left) +
               SumOfAllElements(node->right) + node->data;
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
    root->left->left->right = newNode(5);

    /*get sum of all elements of the above created tree*/
    printf("Sum of all elements of the tree is %d", SumOfAllElements(root));

    getchar();
    return 0;
}
