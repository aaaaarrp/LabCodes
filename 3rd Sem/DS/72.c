
//Program to implement queue to store the elements from different data type (Use union). 

#include <stdio.h>

struct info
{
    int type;
    union
    {
        int i;
        float f;
        char str[50];
    } u;
};

struct queue
{
    int front;
    struct info a[5];
    int end;
};

void create(struct queue *q)
{
    q->front = -1;
    q->end = -1;
}

void print(struct info t)
{
    int eType = t.type;
    switch (eType)
    {
    case 1:
    {
        printf("%d ", t.u.i);
        break;
    }
    case 2:
    {
        printf("%.2f ", t.u.f);
        break;
    }
    case 3:
    {
        printf("%s ", t.u.str);
        break;
    }
    default:
    {
        printf("%d ", t.u.i);
        break;
    }
    }
}

void enqueue(struct queue *q, struct info *e)
{
    if (q->end == 4)
    {
        printf("Queue full!!");
        return;
    }
    if (q->end == -1)
        q->front = q->end = 0;
    else
        q->end++;

    q->a[q->end] = *e;
}

void dequeue(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Empty queue!!");
        printf("\n");
        return;
    }
    printf("Deleted info:");
    print(q->a[q->front]);
    if (q->front == q->end)
        q->front = q->end = -1;
    else
        q->front++;
    printf("\n");
}

void display(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Empty queue!!");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = q->front; i <= q->end; i++)
    {
        print(q->a[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    create(&q);
    int ch = 4;
    do
    {
        printf("\nChoose one:\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &ch);

        if (ch == 1)
        {
            {
                int elementtype;
                printf("\nEnter Element Type(1-int, 2-float, 3-string): ");
                scanf("%d", &elementtype);
                printf("\nEnter element: ");
                struct info data;
                switch (elementtype)
                {
                case 1:
                {
                    data.type = 1;
                    scanf("%d", &data.u.i);
                    break;
                }
                case 2:
                {
                    data.type = 2;
                    scanf("%f", &data.u.f);
                    break;
                }
                case 3:
                {
                    data.type = 3;
                    scanf("%s", data.u.str);
                    break;
                }
                default:
                {
                    data.type = 1;
                    scanf("%d", &data.u.i);
                    break;
                }
                }
                enqueue(&q, &data);
            }
        }
        else if (ch == 2)
        {
            dequeue(&q);
        }
        else if (ch == 3)
        {
            display(&q);
        }

        else
            printf("Exiting!!");
    } while (ch != 4);
}