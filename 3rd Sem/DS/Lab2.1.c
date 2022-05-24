
#include <stdio.h>
#define MAX 20
void readMatrix(int a[10][10], int row, int column);
void printSparse(int b[MAX][3]);
void createSparse(int a[10][10], int row, int column, int b[MAX][3]);
int main()
{
    int a[10][10], b[MAX][3], row, column;
    printf("\nEnter the size of matrix (rows, columns):\n ");
    scanf("%d%d", &row, &column);
    readMatrix(a, row, column);
    createSparse(a, row, column, b);
    printSparse(b);
    return 0;
}
void readMatrix(int a[10][10], int row, int column)
{
    int i, j;
    printf("\nEnter elements of matrix\n\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void createSparse(int a[10][10], int row, int column, int b[MAX][3])
{
    int i, j, k;
    k = 1;
    b[0][0] = row;
    b[0][1] = column;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k - 1;
    }
}
void printSparse(int b[MAX][3])
{
    int i, column;
    column = b[0][2];
    printf("\nSparse form:\n\n");
    for (i = 0; i <= column; i++)
    {
        printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
    }
}