#include "monty.h"

/**
 * main - Entry Point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS); 
}
