#include "holberton.h"

/**
 * _getenv - gets folders in PATH
 * @cash: main struct
 *
 * Return: pointer to folders in PATH
 */
char *_getenv(struct shell cash)
{
	const char *s = "PATH";
	int i, j = 0;

	for (i = 0; cash.env[i][j] != 0; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (s[j] == cash.env[i][j])
			{
				if (j == 3)
					return (&(cash.env)[i][j + 2]);

				continue;
			}
			else
				break;
		}
	}
	return (0);
}
