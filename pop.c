#include "monty.h"

/**
 * popInt - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number
*/
void popInt(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->next == NULL)
	{
		free(top);
		top = NULL;
		*stack = top;
	}
	else
	{
		top = top->next;
		free(top->prev);
		top->prev = NULL;
		*stack = top;
	}
}
