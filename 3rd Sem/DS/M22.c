/*
15 0 0 22 0 -15
0 11 3 0 0 0 
0 0 0 -6 0 0
0 0 0 0 0 0
91 0 0 0 0 0
0 0 28 0 0 0
*/


#include <stdio.h>

void sort(int sm[150][3], int count)
{
    int i, j;
    int temp;
    sm[0][2] = count - 1;
    for (i = 1; i < count; i++)
    {
        for (j = 1; j < count - i; j++)
        {
            if (sm[j + 1][0] < sm[j][0])
            {
                temp = sm[j + 1][0];
                sm[j + 1][0] = sm[j][0];
                sm[j][0] = temp;
                temp = sm[j + 1][1];
                sm[j + 1][1] = sm[j][1];
                sm[j][1] = temp;
                temp = sm[j + 1][2];
                sm[j + 1][2] = sm[j][2];
                sm[j][2] = temp;
            }
            else if (sm[j + 1][0] == sm[j][0] && sm[j + 1][1] < sm[j][1])
            {
                temp = sm[j + 1][0];
                sm[j + 1][0] = sm[j][0];
                sm[j][0] = temp;
                temp = sm[j + 1][1];
                sm[j + 1][1] = sm[j][1];
                sm[j][1] = temp;
                temp = sm[j + 1][2];
                sm[j + 1][2] = sm[j][2];
                sm[j][2] = temp;
            }
        }
    }
}
void transpose(int sm[200][3], int count)
{
    int i, j, temp;
    printf("\n");

    for (j = 1; j < count; j++)
    {

        sm[j][1] = sm[0][1] - sm[j][1] - 1;
    }
    sort(sm, count);
    printf("\n\nTranspose of Matrix \n");
    for (i = 0; i < count; i++)
    {
        printf("a[%d] %d \t %d \t %d\n", i, sm[i][0], sm[i][1], sm[i][2]);
    }
}
void inputMatrix(int a[20][20], int m, int n)
{
    int sm[200][3];
    int s = 1;
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                sm[s][0] = i;
                sm[s][1] = j;
                sm[s][2] = a[i][j];
                s++;
            }
        }
    }
    sm[0][0] = m;
    sm[0][1] = n;
    sm[0][2] = s - 1;
    printf("\n\n");
    printf("The Sparse Matrix is : \n row col value\n");
    for (i = 0; i < s; i++)
    {
        printf("a[%d] %d \t %d \t %d\n", i, sm[i][0], sm[i][1], sm[i][2]);
    }
    transpose(sm, s);
}
int main()
{
    printf("Program to Make Sparse Matrix\n");
    int a[20][20];
    int m, n;
    printf("Enter Matrix : \n");
    printf("Number of rows : ");
    scanf("%d", &m);
    printf("Number of columns : ");
    scanf("%d", &n);
    
    inputMatrix(a, m, n);
}