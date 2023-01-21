#include "monty.h"

/**
 * addInts - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the bytecode file
*/
void addInts(stack_t **stack, unsigned int line_number)
{
	size_t num_of_stack_elements = 0;
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		num_of_stack_elements++;
		current = current->next;
		line_number++;
	}
}