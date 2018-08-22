#include "holberton.h"

/**
 * shell_main - shell main
 *
 * Description: The shell main.  This function contains the loop which prints
 * the shell prompt and handles calling functions for input, output, program
 * execution and some built-ins
 *
 * Return: Returns 0 on normal program termination.  Error functions will
 * handle abnormal function termination.
 */

int shell_main(void)
{
	char *buffer;
	char **parsed_input = NULL; /*malloc to max size*/

	buffer = malloc(sizeof(char) * CHAR_BUF_MAX);
	if (!buffer)
		return (-1);
	parsed_input = malloc(sizeof(void *) * 20);
	if (!parsed_input)
		return (-1);
	do {
		/*Change this to write()*/
		printf(SHELL_PROMPT);
		parsed_input = input_get(buffer, parsed_input);
		input_exec(parsed_input);
	} while (!EOF);
	printf("\n");
	return (0);
}
