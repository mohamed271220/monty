#include "monty.h"

/**
 * fs_open - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void fs_open(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		err(2, f_name);

	fs_read(fd);
	fclose(fd);
}


/**
 * fs_read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void fs_read(FILE *fd)
{
	int line_number, format = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buff, &len, fd) != -1; line_number++)
	{
		format = line_parse(buff, line_number, format);
	}
	free(buff);
}


/**
 * line_parse - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int line_parse(char *buff, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_number, format);
	return (format);
}

/**
 * find_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_top_nodes},
		{"sub", sub_top_nodes},
		{"div", div_top_nodes},
		{"mul", mul_top_nodes},
		{"mod", mod_top_nodes},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			exec_function(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * exec_function - Calls the required function.
 * @func:to be called.
 * @op: string
 * @val: string
 * @ln: line numeber
 * @format: Format specifier
 *
 */
void exec_function(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
