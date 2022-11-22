#include "monty.h"

/**
 * interpreter - interprets and executes monty byte code
 * @instruction: instruction to interpret
 * @line_number: line number
 * @stack: the stack
 */
void interpreter(char *instruction, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	char *p;
	int flag = 0;

	opcode = strtok(instruction, " \n\t");
	if (opcode != NULL)
	{
		input = strtok(NULL, " \n\t");
		p = input;
		flag = string_number(p);
		if (strcmp(opcode, "push") == 0 && (!input || flag == 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			stack = NULL;
			free(instruction);
			instruction = NULL;
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * string_number - sees if string is a number
 * @string: string
 *
 * Return: 0 or 1
 */
int string_number(char *string)
{
	while (string != NULL && *string != '\0')
	{
		if (*string == '-')
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
	stack_t *p, *tmp;

	p = *stack;
	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
		tmp = NULL;
	}
}

/**
 * main - reads lines and runs opcode
 * @argc: number of arguments
 * @argv: given arguments
 */
int main(int argc, char **argv)
{
	FILE *fp;
	size_t size;
	char *instruction;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	instruction = NULL;
	size = 0;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&instruction, &size, fp) != -1)
	{
		interpreter(instruction, line_number, &stack);
		line_number++;
	}
	free_stack(&stack);
	free(instruction);
	instruction = NULL;
	fclose(fp);
	return (0);
}
