
// C program to calculate average of array elements

#include <stdio.h>

double sum(int a[], int i, int size)   //Adding elements using recursion
{
    if (i == size - 1)  //To check if only one element present | last element
        return a[i];
    else
        return (a[i]+ sum(a, i+1, size));   //Compute sum of all elements one by one
}

// Function that return average of an array.
double average(int a[], int size)
{
    return (sum(a, 0, size)/size);
}

int main()
{
    int arr[] = {5, 6, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);  //To find the no of elements

    printf("\nAverage is: %.2lf\n", average(arr, size));

    return 0;
}