#include "monty.h"

/**
* swap - swaps the top two elements of a stack
* @stack: linked list stack to swap
* @line_number: current line number of the bytecode file
*/

void mon_swap(stack_t **stack, unsigned int line_number)
{
int temp = (*stack)->n;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
