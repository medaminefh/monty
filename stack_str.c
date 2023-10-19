#include "main.h"

/**
 * p_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void p_char(stack_t **stack, unsigned int line_number)
{
	int ascii_number;

	if (stack == NULL || *stack == NULL)
		p_str_err(11, line_number);

	ascii_number = (*stack)->n;
	if (ascii_number < 0 || ascii_number > 127)
		p_str_err(10, line_number);
	printf("%c\n", ascii_number);
}

/**
 * p_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l: Interger representing the line number of of the opcode.
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int l)
{
	int ascii_num;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii_num = tmp->n;
		if (ascii_num <= 0 || ascii_num > 127)
			break;
		printf("%c", ascii_num);
		tmp = tmp->next;
	}
	printf("\n");
}
