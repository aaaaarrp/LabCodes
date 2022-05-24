// Span Stock Problem Using Stack

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
typedef struct stack

{
    int top;
    int items[STACK_SIZE];
} stack;

void push(stack *ms, int item)
{
    if (ms->top < STACK_SIZE - 1)
    {
        ms->items[++(ms->top)] = item;
    }
    else
    {
        printf("Stack is full\n");
    }
}

int pop(stack *ms)
{
    if (ms->top > -1)
        return ms->items[(ms->top)--];
    else
        printf("Stack is empty\n");
    return 0;
}

int peek(stack ms)
{
    if (ms.top < 0)
    {
        printf("Stack empty\n");
        return 0;
    }
    return ms.items[ms.top];
}

int isEmpty(stack ms)
{
    if (ms.top < 0)
        return 1;
    return 0;
}

void stockSpan(int prices[], int days)
{
    stack ms;
    int i;
    int span[days];

    if (days == 0)
        return;

    span[0] = 1;
    ms.top = -1;

    push(&ms, 0);

    for (i = 1; i < days; i++)
    {
        while (!isEmpty(ms) && prices[i] > prices[peek(ms)])
        {
            pop(&ms);
        }

        if (isEmpty(ms))
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - peek(ms);
        }
        push(&ms, i);
    }

    for (i = 0; i < days; i++)
    {
        printf("%d  ", span[i]);
    }
    printf("\n\n");
}

int main()
{
    int prices[] = {100, 60, 70, 65, 80, 85, 45, 77, 56, 98, 200};
    int n = sizeof(prices) / sizeof(prices[0]);

    printf("\n\n");
    stockSpan(prices, n);

    return 0;
}
