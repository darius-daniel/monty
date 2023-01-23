#include "monty.h"

GLOBALS *var_group;

/**
 * main - Entry Point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *p_file;
	unsigned int line_number = 0;
	size_t buffer_size = 32;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	var_group = allocateMem(sizeof(GLOBALS));

	var_group->line_buffer = NULL;
	var_group->stack = NULL;
	var_group->arg = NULL;
	var_group->opcode = NULL;

	p_file = openFile(argv[1], "r");
	readFileLine(&var_group->line_buffer, &buffer_size, p_file);
	line_number++;

	while (!feof(p_file) && p_file != NULL)
	{
		createTokensFromString(var_group->line_buffer);
		if (var_group->opcode != NULL && var_group->opcode[0] != '#')
		{
			callOpcodeFuncs(&var_group->stack, line_number);
			var_group->opcode = NULL;
			var_group->arg = NULL;
		}
		readFileLine(&var_group->line_buffer, &buffer_size, p_file);
		line_number++;
	}

	fclose(p_file);
	freeGroup(&var_group);
	return (EXIT_SUCCESS);
}
