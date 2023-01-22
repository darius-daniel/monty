#ifndef MONTY_H
#define MONTY_H

/* =================== Headers =================== */
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


/* ====== Typedefs ====== */
typedef unsigned int uInt;

/* ====================== Structures ============================= */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variable type
 * @line_buffer: a dynamically allocated block of memory containing the
 * line of text read from the bytecode file
 * @opcode: the opcode
 * @arg: argument to opcode
 * @stack: pointer to the top of the stack
 *
 * Description: a collection of all the important variables in one place
*/
typedef struct global_s
{
	char *line_buffer;
	char *opcode;
	char *arg;
	stack_t *stack;
} GLOBALS;

extern GLOBALS *var_group;

/* ++++++ Helper functions +++++ */

/* functions for handling and manipulating files */
FILE *openFile(char *fileName, char *mode);
void readFileLine(char **line, size_t *bufSize, FILE *fileName);

/* functions for dynamic memory allocation */
char **reallocateMem(char **ptr, size_t size);
void *allocateMem(size_t size);

/* functions that handle tokenisation of strings */
void createTokensFromString(char *str);
void freeStack(stack_t **stack);
void freeGroup(GLOBALS **glob_struct);

/* Handling the stack operations */
void callOpcodeFuncs(stack_t **stack, uInt line_number);
void checkFormat(GLOBALS *group, uInt line_number);

/* ++++++ Main Stack Function Prototypes ++++++++ */
void pushInt(stack_t **stack, uInt line_number);
void printAll(stack_t **stack, uInt line_number);
void printInt(stack_t **stack,  uInt line_number);
void popInt(stack_t **stack,  uInt line_number);
void swapInts(stack_t **stack,  uInt line_number);
void addInts(stack_t **stack,  uInt line_number);
void subInts(stack_t **stack,  uInt line_number);
void divInts(stack_t **stack,  uInt line_number);
void mulInts(stack_t **stack,  uInt line_number);
void modInts(stack_t **stack,  uInt line_number);
void doNothing(stack_t **stack,  uInt line_number);
#endif
