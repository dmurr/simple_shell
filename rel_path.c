#include "holberton.h"

/**
 * process_rel_path - converts relative to their absolute path
 * @cash: main struct
 *
 */
void process_rel_path(struct shell cash)
{
	char *full_path, *path, *abs_path;
	const char delim[] = {':', '\0'};
	int i, j;
	int found = 0;

	abs_path = malloc(sizeof(char) * 1024);
	if (!abs_path)
		return;

	full_path = _getenv(cash);

	path = _strtok(full_path, delim);
	while (path)
	{
		for (i = 0; path[i] != '\0'; i++)
			abs_path[i] = path[i];
		abs_path[i] = '/';
		i++;

		for (j = 0; (cash.p_buf)[0][j] != '\0'; j++)
		{
			abs_path[i] = (cash.p_buf)[0][j];
			i++;
		}
		abs_path[i] = '\0';

		if (access(abs_path, F_OK) == 0)
		{
			found = 1;
			if (access(abs_path, X_OK) == 0)
			{
				cash.exec = 1;
				cash.rel = abs_path;
				shell_exec(cash);
				return;
			}
		}
		path = _strtok(NULL, delim);
	}
	if (found == 0)
		shell_error(cash, 1);
	else if (found == 1)
		shell_error(cash, 3);
}
