#include "monty.h"

/**
 * openFile - opens a file and performs the necessary error checks
 * @fileName: path to the path to be opened
 * @mode: file operation mode
 * Return: a pointer to the opened file
 */
FILE *openFile(char *fileName,  char *mode)
{
	FILE *newFile;

	newFile = fopen(fileName, mode);
	if (newFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	return (newFile);
}

/**
 * readFileLine - reads a line of text from a file
 * @fileName: name of the file
 * @line: pointer to the buffer where the text will be stored
 * @size: initial size of the buffer
 * Return: a pointer to the base address of the line
 */
void readFileLine(char **line, size_t *size, FILE *fileName)
{
	int numCharRead;

	*line = NULL;
	numCharRead = getline(line, size, fileName);
	if (numCharRead == -1)
	{
		if (!feof(fileName))
		{
			fprintf(stderr, "Error: Can't read from file\n");
			exit(EXIT_FAILURE);
		}
	}
}

