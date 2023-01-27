#include "monty.h"

/**
 * swapInts - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: an integer
 */
void swapInts(stack_t **stack, uInt line_number)
{
	uInt numStackElems = 0;
	stack_t *current, *second;
	int temp;

	current = *stack;
	while (current != NULL)
	{
		numStackElems++;
		current = current->next;
	}

	if (numStackElems < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeGlobals();
		exit(EXIT_FAILURE);
	}

	current = *stack;
	second = current->next;
	temp = current->n;
	current->n = second->n;
	second->n = temp;
}
