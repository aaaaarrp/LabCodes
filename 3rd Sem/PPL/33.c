
#include <stdio.h>
#include <time.h>

void funR(int *p)
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        printf("%d\n", *p);
        p++;
    }
}

void funV(int p[10000]) 
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        printf("%d\n", p[i]);
    }
}

int main()
{
    int arr[10000] = {0, 0, 0, 0};
    int i;
    clock_t t;
    t = clock();

    for (i = 0; i < 10; i++) // By Reference
    {
        funR(arr);
    }
    t = clock() - t;
    float reference = ((float)t) / CLOCKS_PER_SEC;
    for (i = 0; i < 10; i++) // By Value
    {
        funV(arr);
    }
    t = clock() - t;
    float value = ((float)t) / CLOCKS_PER_SEC;

    printf("\nProcess returned 0 (0x0) execution time by Reference: %.4fs", reference);
    printf("\nProcess returned 0 (0x0) execution time by Value: %.4fs", value);
    printf("\nRatio- Reference:Value :: %.2f : 1\n\n", reference / value);
    return 0;
}