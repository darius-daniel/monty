#include "monty.h"
#include <fcntl.h>

/**
 * main - Entry Point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	char **opcodeAndVal, *p_Line;
	FILE *p_File;
	unsigned int line_number = 0;
	size_t bufSize = 32;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	p_File = openFile(argv[1], "r");
	readFileLine(&p_Line, &bufSize, p_File);
	line_number++;
	while (!feof(p_File) && p_File != NULL)
	{
		printf("line %u: %s", line_number, p_Line);
		opcodeAndVal = createTokensFromString(p_Line);
		printArrayOfPointers(opcodeAndVal);
		readFileLine(&p_Line, &bufSize, p_File);
		line_number++;
	}

	freeArrayOfPointers(opcodeAndVal);
	fclose(p_File);
	return (EXIT_SUCCESS);
}
