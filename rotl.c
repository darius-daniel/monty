#include "monty.h"

/**
 * rotateList - rotates the stack to the top by making the top element of the
 * stack become the last one, and the second top element of the stack become
 * the first one
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the opcode in the bytecode file
*/
void rotateList(stack_t **stack, uInt line_number)
{
	stack_t *top, *current;
	(void)line_number;

	if (*stack != NULL)
	{
		if ((*stack)->next != NULL && (*stack)->prev != NULL)
		{
			current = *stack;
			while (current->next != NULL)
			{
				current = current->next;
			}

			top = *stack;
			*stack = (*stack)->next;
			top->prev = current;
			top->next = NULL;
			current->next = top;
		}
	}
}
