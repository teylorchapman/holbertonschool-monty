#include "monty.h"

/**
 * mon_push - Pushes a value to stack_t linked list
 * @stack: double pointer to the top of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 */
void mon_push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (input != NULL)
	{
		stack_t *ptr = malloc(sizeof(stack_t));

		ptr->n = atoi(input);
		ptr->next = (*stack);
		ptr->prev = NULL;

		if ((*stack) != NULL)
		{
			(*stack)->prev = ptr;
		}
		(*stack) = ptr;
	}
}

/**
 * mon_pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer to the stack
 * @line_number: current working line number of Monty bytecodes file
 */
void mon_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
