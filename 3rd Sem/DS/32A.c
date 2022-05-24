#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    printf("\nNodes Information: \n");
    do
    {
        printf("\nAddress: %p -> Data: %d", &(h->data), h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
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
    Display(Head);
    printf("\n\nNumber of elements: %d\n\n", Length(Head));

    return 0;
}
