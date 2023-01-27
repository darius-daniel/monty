#include "monty.h"

/**
 * printChar - print the char at the top of the stack, followed by a new line
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the opcode in the bytecode file
 * Return: Nothing
*/
void printChar(stack_t **stack, uInt line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		freeGlobals();
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freeGlobals();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
