#include "monty.h"

/**
 * mon_pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number that opcode is called
 */
void mon_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * mon_pop- removes top element from stack
 * @stack: double pointer to stack
 * @line_number: line number
 */
void mon_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void) line_number;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;

	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(node);
}
