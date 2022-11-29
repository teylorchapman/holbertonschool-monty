#include "monty.h"

/**
* mon_swap - swaps the top two elements of a stack
* @stack: linked list stack to swap
* @line_number: current line number of the bytecode file
*/

void mon_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	int len = 0;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *node1 = (*stack);
		stack_t *node2 = (*stack)->next;

		node1->next = node2->next;
		node1->prev = node2;


		node2->prev = NULL;
		node2->next = node1;

		(*stack) = node2;
	}
}
