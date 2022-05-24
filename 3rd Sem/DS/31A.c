
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

void DisplayNodeinfo(struct Node *p)
{
    printf("\n\nNodes Information: \n");
    while (p)
    {
        printf("\nAddress: %p -> Data: %d", &(p->data), p->data);
        p = p->next;
    }
}

void Display(struct Node *p)
{
    printf("\n\nLinked List: ");

    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
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
    int n, A[100];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the numbers: ");
    input(A, n);

    create(A, n);
    DisplayNodeinfo(first);
    Display(first);
    printf("\n\nNumber of elements: %d\n\n", count(first));

    return 0;
}