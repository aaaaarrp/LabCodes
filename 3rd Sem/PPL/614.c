
// Short circuit operation in C

#include <stdio.h>

int main()
{
    int a = 1, b = 1, c = 1, d = 2;
    printf("\nValue of c1 is %d", c);

    //Short Circuiting in || operator
    if (a == b || c++) //c will not increment here due to short circuiting
        printf("\nValue of c2 is %d", c);

    //Short Circuiting in && operator
    if (a == b && c++)  // left side is true
        printf("\nValue of c3 is %d", c); //c will increment here, no short circuiting
    if (a == d && c++)   //left side is false
        printf("\nValue of c4 is %d", c); //c will not increment here, due to short circuiting
}