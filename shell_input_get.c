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
	char new[] = {'\n', '\0'};
	size_t size = CHAR_BUF_MAX;
	ssize_t bytes, ret = 0;

	bytes = getline(&(cash.i_buf), &size, stdin);

	if (bytes == -1 || bytes == 0)
	{
		write(1, new, 2);
		shell_exit(cash);
		return (1);
	}
	ret = input_parse(cash);
	return (ret);
}
