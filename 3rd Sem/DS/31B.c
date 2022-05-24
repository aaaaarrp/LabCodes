
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p != 0)
    {
        count++;
        p = p->next;
    }

    return count;
}

void Display(struct Node *p)
{
    printf("List is: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
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
    int point,num,n, A[100];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the numbers: ");
    input(A, n);

    create(A, n);
    Display(first);

    printf("\nEnter the number after which the node to be inserted: ");
    scanf("%d",&point);
    printf("\nEnter the node to be inserted: ");
    scanf("%d",&num);

    Insert(first,point,num);
    Display(first);

    return 0;
}