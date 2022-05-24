
#include <stdio.h>
float sum(float, float);

void printBinary(unsigned n)
{
    unsigned i;
    printf("Binary: ");
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\n");
}

int main()
{
    unsigned int x = 2, y = 3;

    printf("\nNumbers are 2 & 3\n\n");
    printf("Actual Arguments: \n");
    printBinary(x);
    printf("Decimal: %d\n", (int)x);
    printBinary(y);
    printf("Decimal: %d\n\n", (int)y);

    int res = sum(x, y);

    printf("Result in calling function:\n");
    printBinary(res);
    printf("%d\n\n", (int)res);

    return 0;
}

float sum(float a, float b)
{
    printf("Formal Arguments: \n");
    printBinary(a);
    printf("Decimal: %d\n", (int)a);
    printBinary(b);
    printf("Decimal: %d\n\n", (int)b);

    float res = a + b;

    printf("Result in called function:\n");
    printBinary(res);
    printf("Decimal: %d\n\n", (int)res);

    return res;
}