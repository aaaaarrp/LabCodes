// C program to evaluate value of a postfix
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Stack type
struct Stack
{
	int top;
	unsigned size;
	int *array;
};

// Stack Operations
struct Stack *createStack(unsigned size)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(stack->size * sizeof(int));

	return stack;
}

int isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}

int peek(struct Stack *stack)
{
	return stack->array[stack->top];
}

int pop(struct Stack *stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack *stack, int op)
{
	stack->array[++stack->top] = op;
}


int evaluatePostfix(char *exp)     //to evaluate given postfix expression
{
	// Create a stack of size equal to expression size
	struct Stack *stack = createStack(strlen(exp));
	int i,size=strlen(exp);

	// See if stack was created successfully
	if (!stack)
		return -1;

	// Scan all characters one by one
	for (i = 0; i < size; i++)
	{
		//if the character is blank space then continue
		if (exp[i] == ' ')
			continue;

		// If the scanned character is an operand/ number 
		//Extract the full number -> Push it into the stack.
		else if (isdigit(exp[i]))
		{
			int num = 0;

			//extract full number
			while (isdigit(exp[i]))
			{
				num = num * 10 + (exp[i] - '0');   //converting value 
				i++;
			}

			//push the element in the stack
			push(stack, num);
		}

		// If the scanned character is an operator, 
		// pop two elements from stack apply the operator
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);

			switch (exp[i])
			{
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack);
}


int main()
{
	char exp[] = "10 10 + 60 6 / * 8 –";
	printf("\n Evaluated value: %d\n\n", evaluatePostfix(exp));
	return 0;
}
