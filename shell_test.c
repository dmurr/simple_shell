#include "holberton.h"

/* VERSION 0.1 Only parses on ' '*/
char **input_parse(char *buffer, char **parsed_input)
{
        char *p_holder, delim[] = {' ', '\0'}, new[] = {'\n', '\0'};
        int j = 0;

        p_holder = strtok(buffer, delim);

        while (p_holder)
        {
                parsed_input[j] = p_holder;
                p_holder = strtok(NULL, delim);
                j++;
        }
	parsed_input[j - 1] = strtok(parsed_input[j - 1], new);
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
        parsed_input = input_parse(buffer, parsed_input);
        return (parsed_input);
}

void shell_exec(char **parsed_input)
{
        pid_t c_id;
        int status;

        c_id = fork();
        if (c_id == -1)
        {
                perror("Error:");
                exit(1);
        }
        else if (c_id == 0)
        {
                if (execve(parsed_input[0], parsed_input, NULL) == -1)
                {
                        perror("Error:");
                        exit(1);
                }
        }
        else
		wait(&status);
}

void shell_help(char **parsed_input)
{
        (void) parsed_input;
        printf("helped\n");
}

void shell_exit(char **input)
{
        int status = 0, i;


        if (input[1])
        {
                for (i = 0 ; input[1][i] != '\0'; i++)
                {
                        if (input[1][i] <= '9' && input[1][i] >= '0')
                                status = (status * 10) + (input[1][i] - '0');
                        else
                        {
                                perror("Error");
                                return;
                        }
                }
                exit(status);
        }
        else
        {
                exit(0);
        }
}

/**
 * input_exec - calls functions based on passed string array
 *
 * @parsed_input: string array of arguments
 *
 * Description: Execute main.  This function looks at the first values of the
 * array and uses a switch (for now) to determine what function to call.
 *
 * Return: 0 on normal termination, -1 on abnormal termination.
 */

void (*input_exec(char **parsed_input))(char **)
{
        exec array[] = {
                {"exit", shell_exit},
                {"help", shell_help},
                {NULL, shell_exec}
        };
        int i = 0;

        while (array[i].cmd && strcmp(array[i].cmd, parsed_input[0]))
        {
                i++;
	}
	return(array[i].fun);
}


/**
 * shell_main - shell main
 *
 * Description: The shell main.  This function contains the loop which prints
 * the shell prompt and handles calling functions for input, output, program
 * execution and some built-ins
 *
 * Return: Returns 0 on normal program termination.  Error functions will handle
 * abnormal function termination.
 */

int main(void)
{
	char *buffer;
	char **parsed_input = NULL; /*malloc to max size*/

	if (!(buffer = malloc(sizeof(char) * CHAR_BUF_MAX)))
		return (-1);
	if(!(parsed_input = malloc(sizeof(void *) * 20)))
		return (-1);

	do
	{
		//Change this to write()
		printf(SHELL_PROMPT);
		//call parsed_input = input_get(buffer, parsed_input)
		parsed_input = input_get(buffer, parsed_input);
		//call input_exec(parsed_input)
		input_exec(parsed_input)(parsed_input);
	} while (EOF);
	printf("\n");
	free(buffer);
	free(parsed_input);
	return (0);
}
