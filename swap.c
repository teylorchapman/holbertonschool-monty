#include "monty.h"

/**
* mon_swap - swaps the top two elements of a stack
* @stack: linked list stack to swap
* @line_number: current line number of the bytecode file
* @file: ...
*/

void mon_swap(stack_t **stack, unsigned int line_number)
{
int temp = (*stack)->n;

<<<<<<< HEAD
if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
fclose(file);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
=======
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
>>>>>>> e96d6cd7a499df55e44aeda5aca1507238f59aa8
}
