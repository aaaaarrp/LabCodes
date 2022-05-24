
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,k,n;
    int *array;
    printf("\nEnter the number of elements of array: ");
    scanf("%d", &n);
    array = (int*)calloc(n,sizeof(int));
    if(array == (int*)NULL){
        printf("\nError occured. Out of memory.\n");
        exit(0);
    }
    printf("\nAddress of allocated memory = %u\n", array);
    printf("\nEnter the values of %d array elements:\n",n);
    for(j = 0; j < n; j++)
        scanf("%d",&array[j]);
    printf("\nAddress of 1st member= %u\n",array);
    printf("\nAddress of 2nd member = %u\n",array+1);
    printf("\nSize of array = %u\n",n*sizeof(int));
    for(i = 0; i < n; i++)
        printf("array[%d] = %d\n",i, *(array+i));
    free(array);
    printf("\nAfter the actor of free() the array elements are:\n");
    for(k = 0; k < n; k++)
        printf("array[%d] = %d\n",k, *(array+i));
    printf("\nSince the memory is deallocated, free( function in this compiler is working.");
    return 0;
}