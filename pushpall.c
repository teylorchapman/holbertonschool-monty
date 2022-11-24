#include "monty.h"

/**
<<<<<<< HEAD
=======
 * get_opcode_func - matches opcodes with the corresponding function
 * @opcode: the opcode to match
 *
 * Return: a pointer to the corresponding function
 */
void (*get_opcode_func(char *opcode))(stack_t**, unsigned int line_number)
{
	instruction_t opcode_funcs[] = {
		{"push", mon_push},
		{"pall", mon_pall},
		{"pint", mon_pint},
		{"pop", mon_pop},
		{"swap", mon_swap},
		{"add", mon_add},
		{"nop", mon_nop},
		{NULL, NULL}
	};
	unsigned int i;

for (i = 0; opcode_funcs[i].f != NULL; i++)
{
if (strcmp(opcode, opcode_funcs[i].opcode) == 0)
return (opcode_funcs[i].f);
}
return (opcode_funcs->f);


}

/**
>>>>>>> 1307ae7ece92deffcd3ae98c628b92b299c4cc34
 * mon_push - Pushes a value to stack_t linked list
 * @stack: double pointer to the top of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 */
void mon_push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

<<<<<<< HEAD
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
=======
node = malloc(sizeof(stack_t));
if (!node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

node->prev = node->next = NULL;

if (!(*stack))
(*stack) = node;
else
{
(*stack)->prev = node;
node->next = *stack;
*stack = node;
}
>>>>>>> 1307ae7ece92deffcd3ae98c628b92b299c4cc34
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
