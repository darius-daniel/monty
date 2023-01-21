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

	while (current != NULL)
	{
		current = current->next;
		free(current->prev);
		current->prev = NULL;
	}
}
