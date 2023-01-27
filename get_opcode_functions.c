#include "monty.h"

/**
 * callOpcodeFuncs - handles the various operations
 * that can be performed on the stack
 * @stack: a pointer to the top of the stack
 * @line_number: the line number
 * Return: Nothing
*/
void callOpcodeFuncs(stack_t **stack, uInt line_number)
{
	int i;
	char *opcode = global_vars->opcode;
	instruction_t opcodes[] = {
		{"push", pushInt}, {"pall", printAll},
		{"pint", printInt}, {"pop", popInt},
		{"swap", swapInts}, {"add", addInts},
		{"sub", subInts}, {"div", divInts},
		{"mul", mulInts}, {"mod", modInts},
		{"nop", doNothing}, {"pchar", printChar},
		{"pstr", printStr},
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			break;
		}
	}

	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		freeGlobals();
		exit(EXIT_FAILURE);
	}
}
