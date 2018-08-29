#include "holberton.h"

/**
 * input_get - gets input and parses it with the input_parse()
 *
 * @cash: Shell variable struct
 *
 * Description: Input main.  Function for handling input and input buffer as
 * well as passing the input buffer to the input_parse() function
 *
 * Return: 1 or 0
 */

int input_get(struct shell cash)
{
	size_t size = CHAR_BUF_MAX;

	if (getline(&(cash.i_buf), &size, stdin) == -1)
	{
		cash.exit = 1;
		return (0);
	}
	input_parse(cash);
	return (0);
}
