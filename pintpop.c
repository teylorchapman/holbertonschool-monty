#include "monty.h"

/**
 * mon_pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number that opcode is called
 */
void mon_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else

		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * mon_pop- removes top element from stack
 * @stack: double pointer to stack
 * @line_number: line number
 */
void mon_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void) line_number;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}
