#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

/* provided data structs */

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

/* error.c prototypes */
int usage_error(void);
int file_open_error(char *filename);
int unknown_instruct_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/* Function Prototypes */
void (*get_opcode_func(char *opcode))(stack_t**, unsigned int line_number);
void free_stack(stack_t **stack);
void interpreter(char *instruction, unsigned int line_number, stack_t **stack);
int string_number(char *string);
int main(int argc, char **argv);
char *input;

/* opcode Prototypes */
void mon_push(stack_t **stack, unsigned int line_number);
void mon_pop(stack_t **stack, unsigned int line_number);
void mon_pall(stack_t **stack, unsigned int line_number);
void mon_pint(stack_t **stack, unsigned int line_number);
void mon_swap(stack_t **stack, unsigned int line_number);
void mon_add(stack_t **stack, unsigned int line_number);
void mon_nop(stack_t **stack, unsigned int line_number);
void free_list(stack_t *stack);

#endif
