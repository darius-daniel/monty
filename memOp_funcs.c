#include "monty.h"

/**
 * freeStack - frees the memory occupied by a stack
*/
void freeStack(void)
{
	stack_t *current = global_vars->stack;

	if (current != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
			free(current->prev);
		}
		free(current);
	}
}

/**
 * freeGlobals - frees the memory occupied by a GLOBALS struct
*/
void freeGlobals(void)
{
	fclose(global_vars->p_file);

	if (global_vars->line_buffer != NULL)
		free(global_vars->line_buffer);
	if (global_vars->arg != NULL)
		free(global_vars->arg);
	if (global_vars->opcode != NULL)
		free(global_vars->opcode);

	freeStack();
	free(global_vars);
}
