#include "monty.h"

/**
 * usage_error - Prints usage error messages
 *
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints file opening error messages
 * @filename: name of file
 * Return: EXIT_FAILURE
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_instruct_error - Prints unknown instruction error messages
 * @opcode: opcode where error occurred
 * @line_number: line number in Monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE
 */
int unknown_instruct_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		   line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid mon_push error messages
 * @line_number: line number in Monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
