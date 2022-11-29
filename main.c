#include "monty.h"

/**
 * line_reader - intrepets the line
 * @line: string with line to read
 * @line_number: number of line
 * @stack: pointer to the stack head
 */
void line_reader(char *line, unsigned int line_number, stack_t **stack)
{
	char *fun, *p;
	int i, flag = 0;

	fun = strtok(line, " \t\n");
	if (fun != NULL)
	{
		input = strtok(NULL, " \t\n");
		i = valid(fun);
		p = input;
		flag = is_string_number(p);
		if (strcmp(fun, "push") == 0 && (!input || flag == 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else if (i != VALID)
		{
			print_error(line, line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else
			get_opcode_func(fun, line_number, stack);
	}
}

/**
 * is_string_number - sees if string is a number
 * @string: string
 *
 * Return: 0 or 1
 */
int is_string_number(char *string)
{
	while (string != NULL && *string != '\0')
	{
		if (*string == '-')
		{
			if (isdigit(*(string + 1)) == 0 && string--)
				return (1);
		}
		else if (*string != '-' && isdigit(*string) == 0)
			return (1);
		string++;
	}
	return (0);
}

/**
 * free_stack - frees the stack
 * @stack: stack thats freed
 */
void free_stack(stack_t **stack)
{
	stack_t *p, *t;

	p = *stack;
	while (p)
	{
		t = p;
		p = p->next;
		free(t);
		t = NULL;
	}
}

/**
 * print_error - prints error
 * @line: string with line
 * @line_number: number of line
 */
void print_error(char *line, unsigned int line_number)
{
	(void)line;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
}

/**
 * valid - checks syntax
 * @fun: name of function that can be push
 *
 * Return: 0 or 1
 */
int valid(char *fun)
{
	char name[][10] = {"push", "pall", "pint", "pop", "nop", "swap", "add", ""};
	unsigned int i;

	for (i = 0; name[i][0] != '\0'; i++)
	{
		if (strcmp(name[i], fun) == 0)
			return (1);
	}
	return (0);
}
