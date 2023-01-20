#include "monty.h"

/**
 * pushInt - adds an integer on the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void pushInt(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;
	int num;

	if (opcodeAndVal[1] != NULL)
		num = atoi(opcodeAndVal[1]);

	if (opcodeAndVal[1] == NULL || num == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = allocateMem(sizeof(stack_t));
	new->n = num, new->next = new->prev = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		current = *stack;
		new->next = *stack;
		current->prev = new;
		*stack = new;
	}
}
