#include "monty.h"
#include <ctype.h>

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
	char **arrayOfTokens;
	char *token;
	char *delimiters = " \t\n";
	size_t size = 2;
	int i = 0;

	arrayOfTokens = malloc(size * sizeof(char *));
	if (arrayOfTokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delimiters);
	while (token != NULL && i < 2)
	{
		arrayOfTokens[i] = strdup(token);
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
