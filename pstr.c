#include "monty.h"

/**
 * printStr - prints the string starting at the top of the stack, followed by
 * a new line
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the opcode in the byte file
 */
void printStr(stack_t **stack, uInt line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL && current->n != 0)
	{
		if (current->n < 0 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
