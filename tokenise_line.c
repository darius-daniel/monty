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
void createTokensFromString(char *str)
{
	char *token;
	char *delimiters = " \t\n";

	if (global_vars->opcode != NULL)
	{
		free(global_vars->opcode);
		global_vars->opcode = NULL;
	}

	if (global_vars->arg != NULL)
	{
		free(global_vars->arg);
		global_vars->arg = NULL;
	}

	token = strtok(str, delimiters);
	if (token != NULL)
	{
		global_vars->opcode = malloc(sizeof(char) * (strlen(token) + 1));
		if (global_vars->opcode == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			freeGlobals();
			exit(EXIT_FAILURE);
		}
		strcpy(global_vars->opcode, token);
	}

	token = strtok(NULL, delimiters);
	if (token != NULL)
	{
		global_vars->arg = malloc(sizeof(char) * (strlen(token) + 1));
		if (global_vars->arg == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			freeGlobals();
			exit(EXIT_FAILURE);
		}
		strcpy(global_vars->arg, token);
	}
}
