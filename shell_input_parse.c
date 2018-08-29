#include "holberton.h"

/**
 * input_parse - parses buffer
 *
 * @cash: Shell variable struct
 *
 * Description: Takes input buffer and chunks it into string arguemnts along
 * predefined character patterns (' ', "||", "&&", \n, EOF, etc.)
 *
 * Return: An array of character string arguments in parsed_input.
 */

/* VERSION 0.1 Only parses on ' '*/
int input_parse(struct shell cash)
{
	char *p_holder, delim[] = {' ', '\0'}, new[] = {'\n', '\0'};
	int j = 0;

	p_holder = _strtok(cash.i_buf, delim);

	while (p_holder)
	{
		(cash.p_buf)[j] = p_holder;
		p_holder = _strtok(NULL, delim);
		j++;
	}
	/* check for newline at [j - 1] */
	(cash.p_buf)[j - 1] = _strtok((cash.p_buf)[j - 1], new);
	(cash.p_buf)[j] = p_holder;
	return (0);
}
