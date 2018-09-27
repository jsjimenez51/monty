#include "monty.h"

/**
 * main - primary function with two arguments
 * @argc: count limit to input
 * @argv: filename
 *
 * Description: open file from argv[1] and get opcodes from file
 * Return: success
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename, *buf = NULL;
	size_t bufsize = 0;
	char *seperate, *input;
	stack_t *stk = NULL;
	unsigned int line_number = 1;

	filename = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &bufsize, fp) != -1)
	{
		if (*buf != '\n')
		{
			input = strtok(buf, "\n");
			tokenizer(input, &stk, line_number);
		}
		line_number++;
	}
	fclose(fp);
	free(buf);
	if (stk != NULL)
		free_stk(&stk, line_number);
	return (EXIT_SUCCESS);
}

/**
 * tokenizer - function with 3 arguments
 * @input: buffer input
 * @stk: stack argument
 * @line_number: line count
 *
 * Description: break up the buffer into tokens
 * Return: na
 */
void tokenizer(char *input, stack_t **stk, unsigned int line_number)
{
	char *token;
	char *tokens;

	token = strtok(input, " ");
	if (token == NULL || *token == ' ' || *token == '\n')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!is_num(token))
		{
			printf("L%d: usage: push integer\n", line_number);
			free_stk(stk, line_number);
			exit(EXIT_FAILURE);
		}
		variables.temp = atoi(token);
		findOps(tokens, stk, line_number);
	}
	else
		findOps(token, stk, line_number);
}

/**
 *  is_num - checks if the string is a number
 * @token: the string being checked.
 *
 * Return: 1 if number, 0 if not.
 */
int is_num(char *token)
{
	if (token == NULL)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
