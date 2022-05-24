#include <stdio.h>

int main()
{
    int iResult, a = 10, b = 8, c = 6, d = 5, e =2;
    
    iResult = a - b - c - d;
    printf("%d\n",iResult);
    iResult = a - b + c - d;
    printf("%d\n",iResult);
    iResult = a + b / c / d;
    printf("%d\n",iResult);
    iResult = a + b / c * d;
    printf("%d\n",iResult);
    iResult = a / b * c * d;
    printf("%d\n",iResult);
    iResult = a % b / c * d;
    printf("%d\n",iResult);
    iResult = a % b % c % d;
    printf("%d\n",iResult);
    iResult = a - (b - c) - d;
    printf("%d\n",iResult);
    iResult = (a - (b - c)) - d;
    printf("%d\n",iResult);
    iResult = a - ((b - c) - d);
    printf("%d\n",iResult);
    iResult = a % (b % c) * d * e;
    printf("%d\n",iResult);
    iResult = a + (b - c) * d - e;
    printf("%d\n",iResult);
    iResult = (a + b) * c + d * e;
    printf("%d\n",iResult);
    iResult = (a + b) * (c / d) % e;
    printf("%d\n",iResult);

    return 0;
}