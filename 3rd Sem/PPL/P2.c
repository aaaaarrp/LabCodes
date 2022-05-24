#include <stdio.h>
#include <string.h>

void plural(char name[100])
{
    strcat(name,"s");
}

int main()
{
    char a[100],b[100];
    printf("\nAnimal's name: ");
    scanf("%s",a);
    printf("\nBird's name: ");
    scanf("%s",b);
    plural(a);
    plural(b);
    printf("\nPlural form: %s",a);
    printf("\nPlural form: %s",b);
}