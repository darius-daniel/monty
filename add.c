#include "monty.h"

/**
 * addInts - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the bytecode file
*/
void addInts(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	next = current->next;
	next->n = next->n + current->n;
	*stack = next;
	free(next->prev);
}
