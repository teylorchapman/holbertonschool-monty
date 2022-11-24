#include "monty.h"

/**
 * main - monty program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	size_t size;
	char *line;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	line = NULL;
	size = 0;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		line_reader(line, line_number, &stack);
		line_number++;
		free_stack(&stack);
	}
	free(line);
	line = NULL;
	fclose(fp);
	return (0);
}

/**
 * get_opcode_func - matches opcodes with the corresponding function
 * @fun: the opcode to match
 * @line_number:line number
 * @stack: stack
 *
 * Return: a pointer to the corresponding function
 */
void get_opcode_func(char *fun, unsigned int line_number, stack_t **stack)
{
	instruction_t funcs[] = {
		{"push", mon_push},
		{"pall", mon_pall},
		{"pint", mon_pint},
		{"pop", mon_pop},
		{"nop", mon_nop},
		{"swap", mon_swap},
		{"add", mon_add},
		{NULL, NULL}};

	unsigned int i;

		for (i = 0; funcs[i].opcode != NULL; i++)
		{
			if (strcmp(funcs[i].opcode, fun) == 0)
			{
				funcs[i].f(stack, line_number);
			}
	}
}
