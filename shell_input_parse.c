#include "holberton.h"

/**
 * input_parse - parses buffer
 *
 * @buffer: character string buffer from read()
 * @parsed_input: array to store pasred string arguments
 *
 * Description: Takes input buffer and chunks it into string arguemnts along
 * predefined character patterns (' ', "||", "&&", \n, EOF, etc.)
 *
 * Return: An array of character string arguments in parsed_input.
 */

/* VERSION 0.1 Only parses on ' '*/
char **input_parse(char *buffer, char **parsed_input)
{
	char *mini_buffer;
	int i_read, i_copy, j, num = 1;

	while (num)
	{
		num = next_word(buffer); /*returns number of characters to next word*/
		mini_buffer = malloc(sizeof(char) * num);
		if (mini_buffer == NULL)
		{
			
			return (NULL);
		}
	}

/*	for (i_read = 0 ; buffer[i] != '\0' && buffer[i] != '\n' ; i++)
	{
		/* this loop iterates through buffer

		if (compare against delimiters (struct?)
			//add word to parsed_input[j]
			//j++
			;

			}*/
	return (parsed_input);
}
