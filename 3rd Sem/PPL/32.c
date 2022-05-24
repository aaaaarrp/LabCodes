
#include <stdio.h>

int main()
{

    /* local variable declaration */
    int num = 5; // num variable declared and initialized outside of for loop

    for (int i = 0; i < 1; i++)
    {

        int num;  // same name variable num declared within for loop
        num = 9;  // modify the value of num inside the for loop
        printf("\nValue of a=%d inside the for loop block\n", num); // print he value of variable num inside the for loop
    }

    printf("Value of a=%d outside the for loop block\n", num); // print the value of variable num after the for loop
    return 0;
}