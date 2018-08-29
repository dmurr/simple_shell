#include "holberton.h"

/**
 * _strtok - separates string by token/delim
 * @str: string to tokenize
 * @delim: separation token
 *
 * Description: Searches string for delimiter and replaces it with a null byte
 *
 * Return: A pointer to first substring.
 */
char *_strtok(char *str, const char *delim)
{
	char *b;
	static char *e;
	int idx = 0;
	int j, i = 0;
	char *sub;

	sub = malloc(sizeof(char) * 1024);

	if (str != NULL)
		b = str;
	else
		b = e;

	while (b[idx] == ' ')
	{
		printf("5");
		*b++;
	}

	if (*b == '\0')
	{
		printf("4");
		return (NULL);
	}
	while (b[idx] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (b[idx] != delim[j])
			{
				sub[idx] = b[idx];
			}
			else
			{
				sub[idx] = '\0';

				e = &b[idx + 1];
				free(sub);
				printf("2");
				return (sub);
			}
			j++;
		}
		idx++;
	}
	return (NULL);
}
