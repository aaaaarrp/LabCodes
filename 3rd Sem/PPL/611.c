
// Implicit type Conversion in C

#include<stdio.h>

int main()
{
    int a, b; //declaring a & b
    a = 10;  // initializing a
    char x;  // declaring x
    x = 'A';   //initializing x with A - A's ASCII value is 65
    b = a + x;  //automatic type conversion happening here
    printf("\nValue of b is: %d\n\n",b);
}