#include "monty.h"

/**
 * modInts - finds the modulus between the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the bytecode file
*/
void modInts(stack_t **stack, uInt line_number)
{
	size_t num_of_stack_elements = 0;
	stack_t *current, *next;
	int mod;

	current = *stack;
	while (current != NULL)
	{
		num_of_stack_elements++;
		current = current->next;
	}

	if (num_of_stack_elements < 2 || (*stack)->n == 0)
	{
		if (num_of_stack_elements < 2)
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		else if ((*stack)->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);

		freeGlobals();
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	mod = next->n % (*stack)->n;

	*stack = (*stack)->next;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
