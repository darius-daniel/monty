#include "monty.h"

/**
 * pushInt - adds an integer on the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void pushInt(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;
	char *end_ptr;
	int num;

	if (countPointerArrayVals(opcodeAndVal) > 1)
	{
		end_ptr = allocateMem(sizeof(char) * (strlen(opcodeAndVal[1]) + 1));
		num = strtol(opcodeAndVal[1], &end_ptr, 10);
	}

	if (opcodeAndVal[1] == NULL || *end_ptr != '\0')
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
