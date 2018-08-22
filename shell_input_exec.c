#include "holberton.h"

/**
 * exec_args - forks and executes files in child process
 *
 * @parsed_input: string array of arguments to execute
 *
 * Return: void
 */

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

/*
int main()
{
	char *parsed_input[] = {"exit", "aaaab", NULL};

	input_exec(parsed_input)(parsed_input);

	return (0);
}
*/
