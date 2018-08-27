#include "holberton.h"

/**
 * shell_main - shell main
 *
 * Description: The shell main.  This function contains the loop which prints
 * the shell prompt and handles calling functions for input, output, program
 * execution and some built-ins
 *
 * @argc: number of args (unused for now)
 * @argv: array of args
 * @env: string array of env vars
 *
 * Return: Returns 0 on normal program termination.  Error functions will
 * handle abnormal function termination.
 */

int main(int argc __attribute__((unused)), char *argv[], char **env)
{
	shell cash = {
		NULL, /* i_buf */
		NULL, /* p_buf */
		NULL, /* _env */
		NULL, /* name */
		0, /* count */
		0 /* exit */
	};
	char *prompt = SHELL_PROMPT;

	cash.name = argv[0];
	cash.env = env;
	cash.i_buf = malloc(sizeof(char) * CHAR_BUF_MAX);
	if (!cash.i_buf)
		return (-1);
	cash.p_buf = malloc(sizeof(void *) * 20);
	if (!cash.p_buf)
		return (-1);
	while (1)
	{
		cash.count += 1;
		write(0, prompt, 7);
		cash.exit = input_get(cash);
		if (cash.exit == 1)
			break;
		input_exec(cash)(cash);
		if (cash.exit == 2)
			break;
	}
	free(cash.i_buf);
	free(cash.p_buf);
	printf("\n");
	return (0);
}
