#include "monty.h"

/**
 * createTokensFromString - creates tokens from a string by
 * splitting its contents
 * along a specified delimiter, or string of delimiters
 *
 * @str: the string to be split
 *
 * Return: an array of pointers containing the created tokens
*/
char **createTokensFromString(char *str)
{
	char **arrayOfTokens, *token;
	char *delimiters = " \t\n ";
	unsigned int i = 0;
	size_t size = 1;

	arrayOfTokens = (char **)malloc(size * sizeof(char *));
	if (arrayOfTokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delimiters);
	while (token != NULL)
	{
		arrayOfTokens[i] = strdup(token);

		size++;
		arrayOfTokens = reallocateMem(arrayOfTokens, size);
		token = strtok(NULL, delimiters);
		i++;
	}

	return (arrayOfTokens);
}

/**
 * printArrayOfPointers - prints out the contents of an array of strings
 *
 * @arrayOfPointers: the array of strings
 *
 * Return: Nothing
*/
void printArrayOfPointers(char **arrayOfPointers)
{
	int i;

	for (i = 0; arrayOfPointers[i] != NULL; i++)
		printf("arrayOfPointers[%d]: %s\n", i, arrayOfPointers[i]);
}

/**
 * freeArrayOfPointers - frees the block of memory, on the heap, occupied
 * by an array of tokens
 *
 * @arrayOfPointers: pointer to the block to be freed.
 *
 * Return: Nothing
*/
void freeArrayOfPointers(char **arrayOfPointers)
{
	unsigned int i = 0;

	if (arrayOfPointers != NULL)
	{
		while (arrayOfPointers[i] != NULL)
		{
			free(arrayOfPointers[i]);
			i++;
		}
		free(arrayOfPointers);
	}
}

/**
 * countPointerArrayVals - counts the contents of an array of pointers
 * @arrayOfPointers: the array of pointers
 * Return: number of elements in the array
 */
size_t countPointerArrayVals(char **arrayOfPointers)
{
	unsigned int valNum = 0, i;

	for (i = 0; arrayOfPointers[i] != NULL; i++)
		valNum++;

	return (valNum);
}
