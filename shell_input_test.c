#include "holberton.h"

/* VERSION 0.1 Only parses on ' '*/
char **input_parse(char *buffer, char **parsed_input)
{
        char *p_holder, delim[] = {' ', '\0'};
        int j = 0;

	p_holder = strtok(buffer, delim);

        while (p_holder)
        {
                parsed_input[j] = p_holder;
                p_holder = strtok(NULL, delim);
                j++;
        }
        parsed_input[j] = p_holder;
        return (parsed_input);
}

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
	size_t size = CHAR_BUF_MAX;

	if (getline(&buffer, &size, stdin) == -1)
		return (NULL);
	//might not need the loop if we know sdtin input max
	//while (bytes = read(stdin, &buffer, 1024)) into buffer

	parsed_input = input_parse(buffer, parsed_input);
	//parsed_input = input_parse(buffer, parsed_input)
	//return parsed_input array
	return (parsed_input);
}

int main(void)
{
	char *buffer;
        char **parsed_input = NULL; /*malloc to max size*/
	int i;

	if (!(buffer = malloc(sizeof(char) * CHAR_BUF_MAX)))
                return (-1);
        if(!(parsed_input = malloc(sizeof(void *) * 20)))
                return (-1);

	printf(SHELL_PROMPT);
	input_get(buffer, parsed_input);

        for (i = 0 ; parsed_input[i] ; i++)
	{
                printf("array[%d]: %s\n", i, parsed_input[i]);
        }
	printf("%s, %s, %s, %s\n", parsed_input[0], parsed_input[1], parsed_input[2], parsed_input[3]);
        free(parsed_input);
	free(buffer);
	return (0);
}
