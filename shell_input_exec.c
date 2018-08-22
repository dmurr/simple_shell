#include "holberton.h"

/**
 * exec_args - forks and executes files in child process
 *
 * @parsed_input: string array of arguments to execute
 *
 * Return: void
 */

void exec_args(char **parsed_input)
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

int input_exec(char **parsed_input)
{
	exec_args(parsed_input);

	return (0);
}
