#include "holberton.h"

/**
 * input_get - gets input and parses it with the input_parse()
 *
 * @buffer: buffer to store read() input
 * @parsed_input: array to store string argument array
 *
 * Description: Input main.  Function for handling input and input buffer as
 * well as passing the input buffer to the input_parse() function which returns
 * an array of string arguments.
 *
 * Return: Returns the array of string arguments gotten from input_parse().
 */

char **input_get(char *buffer, char **parsed_input)
{
	int bytes;

	//might not need the loop if we know sdtin input max
	//while (bytes = read(stdin, &buffer, 1024)) into buffer

	//parsed_input = input_parse(buffer, parsed_input)
	//return parsed_input array
}