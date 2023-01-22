#include "monty.h"

/**
 * swapInts - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: an integer
 */
void swapInts(stack_t **stack, uInt line_number)
{
	uInt numStackElems;
	stack_t *current, *first, *second;

	current = *stack;
	while (current != NULL)
	{
		numStackElems++;
		current = current->next;
	}

	if (numStackElems < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeGroup(&var_group);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}
