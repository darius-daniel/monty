#include "monty.h"

/**
 * printAll - prints all the values on the stack, from the top
 * @stack: pointer to top of the stack
 * @line_number: line number of the stack
 */
void
printAll(stack_t **stack, uInt line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
