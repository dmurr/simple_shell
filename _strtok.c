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
	int i, j;

	if (str != NULL)
		b = str;
	else
		b = e;

	if (*b == '\0')
		return (NULL);

	while (b[idx] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (b[idx] == delim[j])
			{
				b[idx] = '\0';

				e = &b[idx + 1];
				return (b);
			}
			j++;
		}
		idx++;
	}
	if (b[idx] == '\0')
	{
		e = &b[idx];
		return (b);
	}
	return (NULL);
}
/*
int main(void)
{
	char *str, *something;
	const char delim[] = {' ', '\0'};

	if(!(str = malloc(sizeof(char) * 1024)))
                return;

	str = strdup("Hello World Something Else");

	something = _strtok(str, delim);
	while (something)
	{
		printf("%s", something);
		something = _strtok(NULL,delim);
		printf("\n");
	}
	return (0);
}
*/
