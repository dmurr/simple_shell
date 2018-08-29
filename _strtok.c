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
	char *b = NULL;
	static char *e;
	int idx = 0;
	int j;

	if (str != NULL)
		b = str;
	else
		b = e;

	if (*b == '\0')
		return (NULL);

	b += _strspn(b, delim);

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
	if ((b[idx - 1] == ' ' || b[idx - 1] == '\n')  && b[idx] == '\0')
	{
		return (NULL);
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
	str = strdup("ls  \n");

	something = _strtok(str, delim);
	while (something)
	{
		printf("%s\n", something);
		something = _strtok(NULL,delim);
	}
	return (0);
}
*/
