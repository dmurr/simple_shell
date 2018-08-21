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
	char *p_holder, delim[] = {' ', '\0'};
	int j = 0;

        printf("3\n");
	p_holder = strtok(buffer, delim);

	while (p_holder)
	{
		parsed_input[j] = p_holder;
		p_holder = strtok(NULL, delim);
		printf("j = %d\n", j);
		j++;
	}
	parsed_input[j] = p_holder;
	return (parsed_input);
}

int main(void)
{
	char *fixed = "hEllo EveRy geNteLmaN", *buffer;
        char **parsed_input = NULL; /*malloc to max size*/
	int i;

	buffer = malloc(sizeof(char) * 25);
        strcpy(buffer, fixed);

	printf("1\n");
	parsed_input = malloc(sizeof(void *) * 10);
	if (parsed_input)
	{
		printf("2\n");
		input_parse(buffer, parsed_input);
	}
	printf("3\n");
	for (i = 0 ; parsed_input[i] ; i++)
	{
		printf("array[%d]: %s]\n", i, parsed_input[i]);
	}
	free(parsed_input);
	return (0);
}
