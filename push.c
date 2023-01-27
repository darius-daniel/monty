#include "monty.h"

/**
 * pushInt - adds an integer on the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void pushInt(stack_t **stack, uInt line_number)
{
	int number;
	char *arg = global_vars->arg;

	checkFormat(global_vars, line_number);

	number = atoi(arg);
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

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		freeGlobals();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		freeGlobals();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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
void checkFormat(global_t *group, uInt line_number)
{
	int i, not_digit = 0;

	if (group->arg == NULL)
		not_digit = 1;
	else
	{
		if (group->arg[0] == '-' || group->arg[0] == '+')
			i = 1;
		else
			i = 0;

		while (group->arg[i] != '\0')
		{
			if (!isdigit(group->arg[i]))
			{
				not_digit = 1;
				break;
			}
			i++;
		}
	}

	if (not_digit == 1)
	{
		freeGlobals();
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
