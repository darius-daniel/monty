#include "monty.h"

/**
 * reallocateMem - reallocates memory on the heap and handles errors on fail
 *
 * @ptr: pointer to the previous block of memory
 * @size: size of the new block to be allocated.
 *
 * Return: pointer to the starting address of the new block
*/
char **reallocateMem(char **ptr, size_t size)
{
	void *newBlock = allocateMem(size * sizeof(char *));

	memcpy(newBlock, ptr, (size - 1) * sizeof(char *));

	return (newBlock);
}

/**
 * allocateMem - allocates a block of memory on the heap and handles errors on
 * fail
 *
 * @size: size of the new block to be allocated.
 *
 * Return: pointer to the starting address of the new block
*/
void *allocateMem(size_t size)
{
	void *newBlock = malloc(size);

	if (newBlock == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeGlobals();
		exit(EXIT_FAILURE);
	}

	return (newBlock);
}

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
 * freeGroup - frees the memory occupied by a GLOBALS struct
 * @glob_struct: address of the struct
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
