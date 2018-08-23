#include "holberton.h"

/**
 * input_get - gets input and parses it with the input_parse()
 *
 * @buffer: buffer to store read() input
 * @parsed_input: array to store string argument array
 *
 * Description: Input main.  Function for handling input and input buffer as
 * well as passing the input buffer to the input_parse() function
 *
 * Return: 1 or 0
 */

int input_get(char *buffer, char **parsed_input)
{
	size_t size = CHAR_BUF_MAX;

	if (getline(&buffer, &size, stdin) == -1)
		return (1);
	input_parse(buffer, parsed_input);
	return (0);
}
