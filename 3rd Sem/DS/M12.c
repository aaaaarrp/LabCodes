
// 100, 80, 60, 70, 60, 75, 85

#include <stdio.h>
#include <stdlib.h>
#define max 10
struct stack
{
    int a[max];
    int top;
} s;
void push(int val)
{
    if (s.top != max - 1)
    {
        s.top++;
        s.a[s.top] = val;
    }
    else
    {
        printf("STACK IS FULL !\n");
    }
}
void pop()
{
    if (s.top != -1)
    {
        s.top--;
    }
    else
    {
        printf("STACK IS EMPTY !\n");
    }
}
int stacktop()
{
    return s.a[s.top];
}
void stackspan(int array[10], int d)
{
    int i, j, k,m;
    int span[10];
    for (i = 0; i < d; i++)
        span[i] = 1;
    push(0);
    span[0] = 1;
    for (i = 1; i < d; i++)
    {
        while (array[i] > array[stacktop()] && s.top != -1)
        {
            pop();
            if (s.top == -1)
            {
                span[i] = i + 1;
            }
            else
                span[i] = i - stacktop();
        }
        push(i);
    }
    for(i=0;i<d;i++)
    {
        m = i - span[i];
        if(span[i]==i+1)
        m = span[i]-1;
        span[i]=array[m];
    }
    
    printf("\nStock Span is : ");
    for (i = 0; i < d; i++)
        printf("%d ", span[i]);
}
int main()
{
    s.top = -1;
    int array[10];
    int d;
    printf("Enter NUMBER OF DAYS : ");
    scanf("%d", &d);
    printf("Enter Prices of each day :\n");
    int i;
    for (i = 0; i < d; i++)
        scanf("%d", &array[i]);
    
    stackspan(array, d);
    return 0;
}