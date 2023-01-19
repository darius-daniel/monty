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
	void *newBlock = (char **)malloc(size * sizeof(char *));

	if (newBlock == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}

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
