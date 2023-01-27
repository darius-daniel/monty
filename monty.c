#include "monty.h"

global_t *global_vars;

/**
 * main - Entry Point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	size_t buffer_size = 32;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_vars = allocateMem(sizeof(global_t));
	global_vars->arg = NULL;
	global_vars->opcode = NULL;
	global_vars->stack = NULL;
	global_vars->line_buffer = NULL;

	global_vars->p_file = openFile(argv[1], "r");
	readFileLine(&global_vars->line_buffer, &buffer_size, global_vars->p_file);
	line_number++;

	while (!feof(global_vars->p_file) && global_vars->line_buffer != NULL)
	{
		createTokensFromString(global_vars->line_buffer);
		if (global_vars->opcode != NULL && global_vars->opcode[0] != '#')
			callOpcodeFuncs(&global_vars->stack, line_number);

		readFileLine(&global_vars->line_buffer, &buffer_size,
													global_vars->p_file);
		line_number++;
	}

	freeGlobals();
	return (EXIT_SUCCESS);
}
