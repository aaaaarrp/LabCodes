
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    printf("\nList is: ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int Delete(struct Node *p, int index) 
{
    //struct Node *q;
    int x = -1, i;
    if (index < 1 || index > Length(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void input(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
}

int main()
{
    int num, n, A[100];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the numbers: ");
    input(A, n);

    create(A, n);
    Display(first);

    printf("\nEnter the number after which the node to be deleted: ");
    scanf("%d",&num);

    Delete(first,(num+1));
    Display(first);

    return 0;
}


