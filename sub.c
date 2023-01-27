#include "monty.h"

/**
 * subInts - subtracts the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the bytecode file
*/
void subInts(stack_t **stack, uInt line_number)
{
	size_t num_of_stack_elements = 0;
	stack_t *current, *next;

	current = *stack;
	while (current != NULL)
	{
		num_of_stack_elements++;
		current = current->next;
	}

	if (num_of_stack_elements < 2)
	{
		freeGlobals();
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	next = current->next;
	next->n = next->n - current->n;
	*stack = next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
