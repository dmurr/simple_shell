#include "holberton.h"

/* fuck wit env later*/
extern char **environ;
char *_getenv(struct shell cash)
{
	const char *s = "PATH";
        int i, j = 0;

        for (i = 0; environ[i][j] != 0; i++)
        {
		for (j = 0; j < 4; j++)
		{
			if (s[j] == environ[i][j])
			{
				if (j == 3)
					return(&environ[i][j+2]);

				continue;
			}
			else
				break;
		}

        }
	return (0);
}
