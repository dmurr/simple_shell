#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strtok - separates string by token/delim
 * @str:
 * @delim: separation token
 *
 * Description: Searches string for delimiter and replaces it with a null byte
 *
 * Return: A pointer to first substring.
 */
char *_strtok(char *str, const char *delim)
{
	static char *b;
	static char *e;
	int idx = 0;
	int i, j;

	if (str != NULL)
		b = str;
	else
		b = e;

/* needs to this to escape infinite loop in main on last substring*/
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
				//printf("b --> %c\n", b[0]);
				//printf("e --> %c\n", e[0]);
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

int main(void)
{
	char *str = "Hello Diego Murray";
	const char delimiter[] = {' ','\0'};
	char *buf;
	char *p;

	buf = malloc(1024 * sizeof(char));
	if(!str)
		return (0);

	strcpy(buf, str);

	p = _strtok(buf, delimiter);
	while (p != NULL)
	{
		printf("Next substring: %s\n", p);
		p = _strtok(NULL, delimiter);
	}

	return (0);
}
