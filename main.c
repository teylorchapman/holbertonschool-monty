#include "monty.h"

/**
 * interpreter - interprets and executes monty byte code
 * @instruction: instruction to interpret
 * @line_number: line number
 * @stack: the stack
 */
void interpreter(char *instruction, unsigned int line_number, stack_t **stack)
{
	instruction_t array[10];
	int i = 0, j = 0;
	void (*func)(stack_t **stack, unsigned int line_number);
	char *opcode, *arg;

	if (*instruction)
	{
		opcode = strtok(instruction, " \n\t");
		if (opcode && opcode[0] != '#')
		{
			arg = strtok(NULL, " \n\t#");
			while (i < 8)
			{
				if (strcmp(opcode, array[i].opcode) == 0)
				{
					if (strcmp(opcode, array[0].opcode) == 0 && arg)
						argument[0] = arg;
					func = array[i].f;
					j = 1;
				}
				if (j)
				{
					func(stack, line_number);
					if (strcmp(argument[0], "FAIL") == 0)
						return;
					argument[0] = "reset";
				}
				else
					dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
							line_number, opcode);
				argument[0] = "FAIL";
				return;
			}
		}
	}
}
