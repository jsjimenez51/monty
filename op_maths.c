#include "monty.h"

/**
 * add - add the top two elements of the stack.
 * @stk: the stack.
 * @line_number: the linenumber.
 *
 * Return: void
 */
void add(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	sum = variables.temp;
	pop(stk, line_number);
	sum += variables.temp;
	pop(stk, line_number);
	variables.temp = sum;
	push(stk, line_number);
}

/**
 * sub - subtracts the top two elements of the stack.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void sub(stack_t **stk, unsigned int line_number)
{
	int diff;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't subtract, stack too short\n", line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	diff = variables.temp;
	pop(stk, line_number);
	diff = variables.temp - diff;
	pop(stk, line_number);
	variables.temp = diff;
	push(stk, line_number);
}

/**
 * div - divide the top two elements of the stack.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void div(stack_t **stk, unsigned int line_number)
{
	int quote;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	if (variables.temp == 0)
	{
		printf("L%d: division by zero\n", line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	quote = variables.temp;
	pop(stk, line_number);
	quote = variables.temp / quote;
	pop(stk, line_number);
	variables.temp = quote;
	push(stk, line_number);
}
