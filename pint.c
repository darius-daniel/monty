#include "monty.h"

/**
 * printInt - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the top of the stack
 * @line_number: the line number
*/
void printInt(stack_t **stack, uInt line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeGroup(&var_group);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}
