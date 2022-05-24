
// Array index checking- when the array size goes out-of-bounds in c

#include <stdio.h>

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    int i,n;
    printf("\nWhich element do u wish to access?\n");
    scanf("%d",&i);
    n=sizeof(a)/sizeof(a[0]);
    if(i>n)
        printf("\nArray out of Bounds!");
    else
        printf("\nThe element is %d",a[i]);
}