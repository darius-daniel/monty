#include "monty.h"

/**
 * pushInt - adds an integer on the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void pushInt(stack_t **stack, uInt line_number)
{
	int number;

	checkFormat(var_group, line_number);

	number = atoi(var_group->arg);
	addToStack(stack, number);
}

/**
 * addToStack - adds a new node to a stack-based doubly-linked list
 * @head: pointer to the head of the dlistint_t list
 * @n: an integer
 * Return: Nothing
 */
void addToStack(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *current = *head;

	new = allocateMem(sizeof(stack_t));

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (current == NULL)
		*head = new;
	else
	{
		current->prev = new;
		new->next = current;
		*head = new;
	}
}

/**
 * addToQueue - adds a new node to a queue-based doubly-linked list
 * @head: pointer to the head of the dlistint_t list
 * @n: an integer
 * Return: Nothing
 */
void addToQueue(stack_t **head, const int n)
{
	stack_t *new, *current, *previousNode;

	new = allocateMem(sizeof(stack_t));

	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		previousNode = NULL;
		while (current != NULL)
		{
			previousNode = current;
			current = current->next;
		}
		previousNode->next = new;
		new->prev = previousNode;
	}
}


/**
 * checkFormat - checks the input format to the function
 * @line_number: opcode line number
 * @group: a struct containing a group of global variables
 * Return: 1 string in var_group can be converted to a num. 0 otherwise
*/
void checkFormat(GLOBALS *group, uInt line_number)
{
	int i = 0, not_digit = 0;

	if (!group->arg)
		not_digit = 1;
	else
	{
		while (group->arg[i] != '\0')
		{
			if (i == 0 && (group->arg[i] == '-' || group->arg[i] == '+'))
			{
				i++;
				continue;
			}

			if (*group->arg < 48 || *group->arg > 57)
				not_digit = 1;
			i++;
		}
	}

	if (not_digit == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeGroup(&var_group);
		exit(EXIT_FAILURE);
	}
}
