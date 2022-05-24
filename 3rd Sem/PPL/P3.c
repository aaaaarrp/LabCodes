
#include <stdio.h>
#include <stdlib.h>
void getMinMax(int *t)
{
    int i = 0, min = 0, max = 0;
    min = max = *t;

    for(i = 0; i < 5; i++)
    {
        if(min > *(t + i))
        {
            min = *(t + i);
        }

        if(max < *(t + i))
        {
            max = *(t + i);
        }
    }
    printf("Min: %d\nMax: %d\n", min, max);
}   
int main()
{
    char *city[5];
    int *temps, i = 0, j = 0;
    int min = 0, max = 0;

    for(i = 0; i < 5; i++)
    {
        city[i] = (char*)malloc(50);
    }
    temps = (int*)malloc(25 * sizeof(int));
    for(i = 0; i < 5; i++)
    {
        printf("Enter city: ");
        scanf("%s", city[i]);
        printf("Yearly temperatures of city %d:\n", i + 1);
        for(j = i * 5; j < (i * 5) + 5; j++)
        {
            scanf("%d",temps + j);
        }
        getMinMax(temps+ (i*5));
    }
}