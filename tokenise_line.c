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

	token = strtok(str, delimiters);
	if (token != NULL)
	{
		var_group->opcode = allocateMem(sizeof(char) * (strlen(token) + 1));
		strcpy(var_group->opcode, token);
	}

	token = strtok(NULL, delimiters);
	if (token != NULL)
	{
		var_group->arg = allocateMem(sizeof(char) * (strlen(token) + 1));
		strcpy(var_group->arg, token);
	}
}
