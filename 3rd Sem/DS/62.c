
//	Write a program using recursive function to reverse the circular linked list.

#include <stdio.h>
#include <stdlib.h>

int x;
struct node
{
    int data;
    struct node *next;
} *head = NULL,*last = NULL,*cur = NULL;

void display()
{
    struct node *p;
    p = head;
    int i = 1;
    printf("List is: ");
    do
    {
        printf(" %d ", p->data);
        i++;
        p = p->next;
    } while (p != head);
}

void create(int size)
{
    
    int i, d;

    for (i = 0; i < size; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            printf("Data for node %d : ", i+1);
            scanf("%d", &d);
            head->data = d;
            head->next = head;
            cur = head;
            last = head;
        }
        else
        {
            struct node *p;
            p = (struct node *)malloc(sizeof(struct node));
            printf("Data for node %d : ", i+1);
            scanf("%d", &d);
            p->data = d;
            cur->next = p;
            p->next = head;
            last = p;
            cur = p;
        }
    }
    printf("\n");

}

void reverse(struct node *p, struct node *q)
{

    while (x == 0)
    {
        struct node *r = q->next;
        q->next = p;
        p = q;
        q = r;
        if (p == head)
            x = 1;
        reverse(p, q);
    }
    if (x == 1)
        head = head->next;
}

int main()
{
    int size;
    printf("\nNo of elements in Circular linked list : ");
    scanf("%d", &size);

    create(size);
    display();

    printf("\n\nAFTER REVERSING : \n\n");

    struct node *p = head;
    struct node *q = p->next;
    struct node *r = q->next;

    reverse(p, q);
    display();

    printf("\n\n");
}