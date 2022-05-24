
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

struct node {
    int data;
    int vc;
    struct node *left, *right;
};

int vCover(struct node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    if (root->vc != 0)
        return root->vc;

    int size_incl = 1 + vCover(root->left) + vCover(root->right);

    int size_excl = 0;
    if (root->left)
        size_excl += 1 + vCover(root->left->left) + vCover(root->left->right);
    if (root->right)
        size_excl += 1 + vCover(root->right->left) + vCover(root->right->right);

    root->vc = min(size_incl, size_excl);

    return root->vc;
}

struct node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data        = data;
    temp->left = temp->right = NULL;
    temp->vc                 = 0;
    return temp;
}

int main() {

    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    root->right              = newNode(22);
    root->right->right       = newNode(25);

    printf("Size of the smallest vertex cover is %d \n\n", vCover(root));

    return 0;
}