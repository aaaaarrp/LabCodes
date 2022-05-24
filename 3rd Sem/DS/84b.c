// C program to find maximum in a Binary Tree
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A tree node
struct Node {
	int data;
	struct Node *left, *right;
};

// function to create a new node
struct Node* newNode(int data)
{
	struct Node* node
		= (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Returns maximum value in a given Binary Tree
int findMax(struct Node* root)
{
	// Base case
	if (root == NULL)
		return INT_MIN;

	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	int res = root->data;
	int lres = findMax(root->left);
	int rres = findMax(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}


int main(void)
{
	struct Node* NewRoot = NULL;
	struct Node* root = newNode(2);
	root->left = newNode(7);
	root->right = newNode(55);
	root->left->right = newNode(6);
	root->left->right->left = newNode(1);
	root->left->right->right = newNode(11);
	root->right->right = newNode(9);
	root->right->right->left = newNode(4);


	printf("\nMaximum element is %d \n", findMax(root));

	return 0;
}

