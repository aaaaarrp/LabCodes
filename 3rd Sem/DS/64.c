
// write a program  to convert the infix expression to its postfix equivalent using stack.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
	int top;
	unsigned size;
	int *array;
};

struct Stack *createStack(unsigned size) //creating a stack
{
	struct Stack *stack = (struct Stack *)
		malloc(sizeof(struct Stack));
	if (!stack)
		return NULL;

	stack->top = -1; 
	stack->size = size;
	stack->array = (int *)malloc(stack->size * sizeof(int));
	return stack;
}

int empty(struct Stack *stack)
{
	return stack->top == -1;
}

char peek(struct Stack *stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
	if (!empty(stack))
		return stack->array[stack->top--]; //return top element and decrement
	return 0;
}

void push(struct Stack *stack, char op)
{
	stack->array[++stack->top] = op; //increment then push element on top
}

int operandcheck(char ch) //Valid operand checking
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) //Precedence chcking
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int converter(char *exp)
{
	int i, k; //i for infix and k for postfix

	struct Stack *stack = createStack(strlen(exp)); //strlen(exp) is the expression size

	int size = strlen(exp);
	
	if (!stack) // See if stack was created successfully
		return -1;
	
	// Scan all characters one by one
	for (i = 0, k = -1; i < size; i++)
	{  
		//checks if it's an operand
		if (operandcheck(exp[i])) 
			exp[++k] = exp[i];	  //increment of the position and put it in postfix

		else if (exp[i] == '(')     //if its a '(' - put it in stack
			push(stack, exp[i]);

		else if (exp[i] == ')')     //if its a ')'
		{
			while (!empty(stack) && peek(stack) != '(') //Until stack becomes empty and top element is ')'
				exp[++k] = pop(stack);					// pop out and put it in postfix

			if (empty(stack) && peek(stack) != '(')
				return -1;
			else
				pop(stack);
		}

		else // If it sees an operator
		{
			while (!empty(stack) && precedence(exp[i]) <= precedence(peek(stack)))  //Until Stack is empty 
				exp[++k] = pop(stack);     //if pre of exp is lesser than pre of top element of stack - pop it out
			push(stack, exp[i]);     //If higher pre of element, push it in stack
		}

	}

	while (!empty(stack))
	{
		exp[++k] = pop(stack);
	}
	exp[++k] = '\0';
	return 0;

}

int main()
{
	char exp[] = "((A+B)*C-D)*E";
	converter(exp);
	printf("\n %s \n\n", exp);
}