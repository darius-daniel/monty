#include "monty.h"

/**
 * pushInt - adds an integer on the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void pushInt(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num;

	checkFormat(opcodeAndVal, line_number);

	num = atoi(opcodeAndVal[1]);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->next = *stack;
	new->prev = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		*stack = new;
	}
}


/**
 * checkFormat - checks the input format to the function
 * @arrayOfPointers: opcode and value
 * @line_number: opcode line number
*/
void checkFormat(char **arrayOfPointers, unsigned int line_number)
{
	char *str_num;
	int i = 0, not_digit = 0;

	if (arrayOfPointers[1] != NULL)
	{
		str_num = arrayOfPointers[1];
		while (str_num[i] != '\0')
		{
			if (str_num[i] < 48 || str_num[i] > 57)
			{
				not_digit = 1;
				break;
			}
			i++;
		}
	}

	if (opcodeAndVal[1] == NULL || not_digit == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
