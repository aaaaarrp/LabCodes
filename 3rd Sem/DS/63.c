// Tower of Hanoi

#include <stdio.h>

void TOH(int n, char from, char aux, char to)
{
    if(n > 0)
    {
        TOH(n - 1, from, to, aux);
        printf("\n Move disk %d from Rod %c to Rod %c", n, from, to);
        TOH(n - 1, aux, from, to);
    }

}

int main()
{
    int n = 3;  //no of disk
    TOH(n, 'A', 'B', 'C');
    printf("\n\n");
}