
#include<stdio.h>

int main()
{
    int k, n, a[10][10], indeg[10], flag[10], count = 0;

    printf("Enter the no of vertices:\n");
    scanf("%d", &n);

    printf( "Enter the adjacency matrix:\n");
    for (int i = 0; i < n-1; i++)
    {
       printf("Enter Row %d\n", i+1);
        for (int j = 0; j <n; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    for (int i  = 0; i < n; i++)
    {
        indeg[i] = 0;
        flag[i] = 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            indeg[i] = indeg[i] + a[j][i];

    printf("\nThe topological order is:");

    while (count < n)
    {
        for (int k = 0; k < n; k++)
        {
            if ((indeg[k] == 0) && (flag[k] == 0))
            {
                printf("%d ", k+1);
                flag[k] = 1;
            }

            for (int i = 0; i < n; i++)
            {
                if (a[i][k] == 1)
                    indeg[k]--;
            }
        }

        count++;
    }

    return 0;
}