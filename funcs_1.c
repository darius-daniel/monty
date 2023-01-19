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

/**
 * printAll - prints all the values on the stack, from the top
 * @stack: pointer to top of the stack
 * @line_number: line number of the stack
 */
void printAll(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}

/**
 * printInt - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the top of the stack
 * @line_number: the line number
*/
void printInt(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}

/**
 * popInt - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number
*/
void popInt(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->next == NULL)
	{
		free(top);
		top = NULL;
		*stack = top;
	}
	else
	{
		top = top->next;
		free(top->prev);
		top->prev = NULL;
		*stack = top;
	}
}
