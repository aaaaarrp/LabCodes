
//Floating point addition is not associative in C

#include <stdio.h>
int main()
{
    float a, b, c;
    a = 90000000.0;
    printf("\nValue of float a:90000000.0\n");
    b = -90000000.0;
    printf("Value of float b:-90000000.0\n");
    c = 1;
    printf("Value of float c:1\n");
    printf("\n(a+b)+c=%f", (a + b) + c);
    printf("\na+(b+c)=%f", a + (b + c));
    return 0;
}