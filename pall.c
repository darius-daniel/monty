#include "monty.h"

/**
 * printAll - prints all the values on the stack, from the top
 * @stack: pointer to top of the stack
 * @line_number: line number of the stack
 */
void
printAll(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if (*stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
