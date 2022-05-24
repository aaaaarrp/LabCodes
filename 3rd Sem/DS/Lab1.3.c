
//C Program to sort numbers using Insertion Sort

#include<stdio.h>
void InsertionSort(int a[], int n)
{
    int j, p;
    int tmp;
    for(p = 1; p < n; p++)
    {
        tmp = a[p];
        for(j = p; j > 0 && a[j-1] > tmp; j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}
 
int main()
{
    int i, n, a[10];
    printf("\nEnter number of elements\n");
    scanf("%d",&n);
    printf("\nEnter %d numbers\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    InsertionSort(a,n);
    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
        printf("%d  ",a[i]);
    printf("\n");
    return 0;
}