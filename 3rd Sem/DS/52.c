
//Implement stack to store the elements from different data type.

#include <stdio.h>
#define SZ (20)

union stack_s
{
    struct stack_int
    {
        int top;
        int arr[SZ];
    } istack;

    struct stack_char
    {
        char top;
        char arr[SZ];
    } cstack;

    struct stack_float
    {
        float top;
        float arr[SZ];
    } fstack;
};

int main()
{
    union stack_s stack_elm;

    stack_elm.istack.arr[0] = 0x1234;
    printf("\nstack of integers = %x\n", stack_elm.istack.arr[0]);

    stack_elm.cstack.arr[0] = 'A';
    printf("stack of chars = %c\n\n", stack_elm.cstack.arr[0]);

    return 0;
}
