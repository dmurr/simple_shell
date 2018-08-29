#include "holberton.h"

/**
 * shell_exec - forks and executes files in child process
 *
 * @cash: Shell variable struct
 *
 * Return: void
 */

void shell_exec(struct shell cash)
{
	pid_t c_id;
	int status;

/* below code block*/
	if (access(cash.name, X_OK) == -1)
	{
		shell_error(cash, 3);
		exit(99);
	}

	c_id = fork();
	if (c_id == -1)
	{
		perror("Error:");
		exit(1);
	}
	else if (c_id == 0 && cash.exec == 0)
	{
		if (execve((cash.p_buf)[0], cash.p_buf, NULL) == -1)
		{
			shell_error(cash, 1);
			free(cash.i_buf);
			free(cash.p_buf);
			exit(1);
		}
	}
	else if (c_id == 0 && cash.exec == 1)
	{
		if (execve(cash.rel, cash.p_buf, NULL) == -1)
		{
			shell_error(cash, 1);
			free(cash.i_buf);
			free(cash.p_buf);
			exit(1);
		}
	}
	else
		wait(&status);
}

/**
 * shell_env - prints environment
 * @cash: Shell variable struct
 *
 * Return: void
 */

void shell_env(struct shell cash)
{
	char *buf, new[] = {'\n', '\0'};
	int i = 0;

	for ( ; (buf =  cash.env[i]) != NULL ; i++)
	{
		write(0, buf, _strlen(buf));
		write(0, new, 1);
	}
}


/**
 * shell_exit - exits shell with exit code upon invocation
 *
 * @cash: Shell variable struct
 *
 * Return: void
 */

void shell_exit(struct shell cash)
{
	int stat = 0, i;

	if ((cash.p_buf)[1])
	{
		for (i = 0 ; (cash.p_buf)[1][i] != '\0'; i++)
		{
			if ((cash.p_buf)[1][i] <= '9' &&
			    (cash.p_buf)[1][i] >= '0')
			{
				stat = (stat * 10) + ((cash.p_buf)[1][i] - '0');
			}
			else
			{
				shell_error(cash, 2);
				return;
			}
		}
		free(cash.i_buf);
		free(cash.p_buf);
		exit(stat);
	}
	else
	{
		free(cash.i_buf);
		free(cash.p_buf);
		exit(0);
	}
}

/**
 * input_exec - calls functions based on passed string array
 *
 * @cash: Shell variable struct
 *
 * Description: Execute main.  This function looks at the first values of the
 * array and uses a switch (for now) to determine what function pointer
 * to return.
 *
 * Return: pointer to function
 */

void (*input_exec(struct shell cash))(struct shell)
{
	exec array[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, direct_path}
	};
	int i = 0;

	while (array[i].cmd && _strcmp(array[i].cmd, (cash.p_buf)[0]))
	{
		i++;
	}
	return (array[i].fun);
}
