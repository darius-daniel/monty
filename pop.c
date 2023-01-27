#include "monty.h"

/**
 * popInt - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number
*/
void popInt(stack_t **stack, uInt line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeGlobals();
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL && (*stack)->prev == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
