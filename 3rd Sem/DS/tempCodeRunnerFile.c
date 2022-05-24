#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define N 20

struct node
{
    struct et* data;
    struct node *next;
};

typedef struct node node;

node *top;

struct et
{
    char value;
    struct et* left, *right;
};

int isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return 1;
	return 0;
}

struct et* newNode(char v)
{
	struct et* temp = (struct et*)malloc(sizeof(char));
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
};

void initialize()
{
    top = NULL;
}

void push(struct et* value)
{
    node *tmp;
    tmp = (struct node*)malloc(sizeof(node));
    tmp -> data = value;
    tmp -> next = top;
    top = tmp;
}

void pop()
{
    node *tmp;
    tmp = top;
    top = top->next;
    free(tmp);
}

struct et* Top()
{
    return top->data;
}

int isempty()
{
    return top==NULL;
}


struct et* constructTree(char postfix[])
{
	struct et *t, *t1, *t2;

	for (int i=0; i<strlen(postfix); i++)
	{

		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]);
			push(t);
		}
		else
		{
			t = newNode(postfix[i]);

			t1 = Top();
			pop();
			t2 = Top();
			pop();


			t->right = t1;
			t->left = t2;

			push(t);
		}
	}

	t = Top();
	pop();

	return t;
}

void inorder(struct et *t)
{
	if(t)
	{
		if (isOperator(t->value)) {
		 	printf("(");

    	}
		inorder(t->left);
		printf("%c", t->value);
		inorder(t->right);
		if (isOperator(t->value)) {
		   printf(")");
		}
	}

}



int main()
{
    initialize();
    char postfix[100];
	printf("\nEnter a postfix expression : ");
	scanf("%s",postfix);
    struct et* r = constructTree(postfix);
    printf("\nInfix expression is \n");
    inorder(r);
    return 0;
}