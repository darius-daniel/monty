#include "monty.h"

/**
 * pushInt - adds an integer on the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void pushInt(stack_t **stack, uInt line_number)
{
	stack_t *new;
	int num;

	checkFormat(var_group, line_number);

	num = atoi(var_group->arg);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeGroup(&var_group);
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
 * @line_number: opcode line number
 * @group: a struct containing a group of global variables
 * Return: 1 string in var_group can be converted to a num. 0 otherwise
*/
void checkFormat(GLOBALS *group, uInt line_number)
{
	char *str_num;
	int i = 0, not_digit = 0;

	str_num = group->arg;
	if (str_num != NULL)
	{
		while (str_num[i] != '\0')
		{
			if (str_num[i] < '0' || str_num[i] > '9')
			{
				not_digit = 1;
				break;
			}
			i++;
		}
	}

	if (str_num == NULL || not_digit == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeGroup(&var_group);
		exit(EXIT_FAILURE);
	}
}
