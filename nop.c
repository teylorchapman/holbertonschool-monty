#include "monty.h"

/**
* mon_nop - does nothing
* @stack: linked list stack that doesn't do anything
* @line_number: current line number of bytecode file
*/

void mon_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
