
//Functional side effect in C

#include <stdio.h>

int a = 5;

int fun1()
{
    a = 17;
    return 3;
}

int main()
{
    a = a + fun1();
    printf("Value of a:%d", a);
}
