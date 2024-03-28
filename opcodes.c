#include "monty.h"


/**
* add_stack - Adds a node to the stack.
* @new_node: Pointer
* @ln: Interger
*/

void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
* print_stack - Adds a node to the stack.
* @stack: Pointer
* @line_number: line number
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* pop - Adds a node to the stack.
* @stack: Pointer
* @line_number: Interger
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		detailed_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
* print_top - Prints the top node of the stack.
* @stack: Pointer
* @line_number: Interger
*/

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		detailed_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
* nop - Does nothing.
* @stack: Pointer
* @line_number: Interger
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


