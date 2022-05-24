
// Program to create a binary tree with nine nodes and traverse it in Inorder, Preorder and Postorder.
//Show the traversal output.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left; //pointer to left and right child
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL; //Since this is a new node, no children as of now
    newNode->right = NULL;
    return (newNode);
}

void printPostorder(struct node *node) //Postorder is Left-Right-Root
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

void printInorder(struct node *node) //In-order is Left-Root-Right
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(struct node *node) //Pre-order is Root-Left-Right
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    printf("\nPre-Order traversal of binary tree is \n");
    printPreorder(root);

    printf("\nIn-Order traversal of binary tree is \n");
    printInorder(root);

    printf("\nPost-Order traversal of binary tree is \n");
    printPostorder(root);

}