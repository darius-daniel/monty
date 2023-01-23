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
		freeGroup(&var_group);
		exit(EXIT_FAILURE);
	}

	return (newBlock);
}

/**
 * freeStack - frees the memory occupied by a stack
 * @stack: pointer to the top of the stack
*/
void freeStack(stack_t **stack)
{
	stack_t *current = *stack;
	if (*stack != NULL)
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
void freeGroup(GLOBALS **glob_struct)
{
	free((*glob_struct)->line_buffer);
	free((*glob_struct)->opcode);
	free((*glob_struct)->arg);
	freeStack(&var_group->stack);
	free(*glob_struct);
}
