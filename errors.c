#include "monty.h"

/**
 * err - prints error messages
 * @code: codes for the errors
 */

void err(int code, ...)
{
	int line_num;
	char *op;
	va_list ag;

	va_start(ag, code);

	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr,
				"Error: Can't open file %s\n", va_arg(ag, char *));
			break;
		case 3:
			line_num = va_arg(ag, int);
			op = va_arg(ag, char *);

			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n",
					va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err1 - prints error messages for stacks
 * @code: codes for errors
 */

void err1(int code, ...)
{
	int line_num;
	char *op;
	va_list ag;

	va_start(ag, code);

	switch (code)
	{
		case 6:
			fprintf(stderr,
				"L%d: can't pint, stack empty\n", va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr,
				"L%d: can't pop an empty stack\n", va_arg(ag, int));
			break;
		case 8:
			line_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr,
				"L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr,
				"L%d: division by zero\n", va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err2 - error handling for strings
 * @code: codes for errors
 */

void err2(int code, ...)
{
	int line_num;
	va_list ag;

	va_start(ag, code);

	line_num = va_arg(ag, int);

	switch (code)
	{
		case 10:
			fprintf(stderr,
				"L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr,
				"L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}