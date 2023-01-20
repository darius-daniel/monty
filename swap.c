#include "monty.h"

/**
 * swapInt - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: an integer
 */
void swapInts(stack_t **stack, unsigned int line_number)
{
	unsigned int numStackElems;
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		numStackElems++;
		current = current->next;
	}

	if (numStackElems < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
