#include "monty.h"

/**
* mon_add - adds the first two elements of a stack replaces
* both with sum
* @stack: linked list stack to add
* @line_number: current line number of bytecode file
*/

void mon_add(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;

if (!temp || !temp->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
free_stack(stack);
err();
}
temp->next->n += temp->n;
*stack = temp->next;
(*stack)->prev = NULL;
free(temp);
}
