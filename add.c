#include "monty.h"

/**
* mon_add - adds the first two elements of a stack replaces
* both with sum
* @stack: linked list stack to add
* @line_number: current line number of bytecode file
*/

void mon_add(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	int len = 0;
	int sum = 0;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		mon_pop(stack, line_number);
	}
}
