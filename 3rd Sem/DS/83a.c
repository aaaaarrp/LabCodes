
// C program to check whether a given Binary Tree is Strictly Binary Tree or not
// 0 or 2

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Tree node structure */
struct Node
{
	int key;
	struct Node *left, *right;
};

/* allocates a new node with the
given data and NULL left and right pointer. */
struct Node *newNode(char data)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->key = data;
	newNode->right = newNode->left = NULL;
	return newNode;
}

/* This function tests if a binary tree is a Strictly Binary binary tree. */
bool isSBTree (struct Node* root)
{
	// If empty tree
	if (root == NULL)
		return true;

	// If leaf node = 0
	if (root->left == NULL && root->right == NULL)
		return true;

	/* If both left and right are not NULL, and left & right subtrees
	 are full   = 2 */
	if ((root->left) && (root->right))
		return (isSBTree(root->left) && isSBTree(root->right));

	// when none of the above if conditions work
	return false;
}


int main()
{
	struct Node* root = NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);

	root->left->right = newNode(40);
	root->left->left = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);

	root->left->left->left = newNode(80);
	root->left->left->right = newNode(90);
	root->left->right->left = newNode(80);
	root->left->right->right = newNode(90);
	root->right->left->left = newNode(80);
	root->right->left->right = newNode(90);
	root->right->right->left = newNode(80);
	root->right->right->right = newNode(90);

	if (isSBTree(root))
		printf("\nThe Binary Tree is Strictly Binary\n");
	else
		printf("\nThe Binary Tree is not Strictly Binary\n");

	return(0);
}

