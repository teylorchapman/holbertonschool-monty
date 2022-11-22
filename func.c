#include "monty.h"

/**
 * mon_stack - stack mode setter
 * @stack: stack
 * @line_number: line number
 */
void mon_stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	argument[1] = "stack";
}

/**
 * mon_queue - queue mode setter
 * @stack: stack
 * @line_number: line number
 */
void mon_queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	argument[1] = "queue";
}
