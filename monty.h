#ifndef MONTY_H
#define MONTY_H

#define _GNU_SRC
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
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

typedef void (*op_func)(stack_t **, unsigned int);
extern stack_t *head;

void fs_open(char *f_name);
void fs_read(FILE *);
int line_parse(char *buff, int line_number, int format);
stack_t *create_node(int n);
int char_count(FILE *);
void find_function(char *, char *, int, int);
void print_stack(stack_t **, unsigned int);
void free_nodes(void);
void add_queue(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void exec_function(op_func, char *, char *, int, int);
void nop(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void add_top_nodes(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void div_top_nodes(stack_t **, unsigned int);
void sub_top_nodes(stack_t **, unsigned int);
void mod_top_nodes(stack_t **, unsigned int);
void mul_top_nodes(stack_t **, unsigned int);
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void err(int err_code, ...);
void detailed_err(int err_code, ...);
void string_err(int err_code, ...);

#endif
