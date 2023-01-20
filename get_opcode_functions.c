#include "monty.h"

/**
 * callOpcodeFuncs - handles the various operations
 * that can be performed on the stack
 * @stack: a pointer to the top of the stack
 * @line_number: the line number
 * Return: Nothing
*/
void callOpcodeFuncs(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"push", pushInt}, {"pall", printAll},
		{"pint", printInt}, {"pop", popInt},
		{"swap", swapInts}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcodeAndVal[0]) == 0)
		{
			opcodes[i].f(stack, line_number);
			break;
		}
	}

	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcodeAndVal[0]);
		exit(EXIT_FAILURE);
	}
}
