#include <stdio.h>
#include <stdlib.h>

/**
 * _strtok - separates string by token/delim
 * @str:
 * @delim: separation token
 *
 * Description:
 *
 * Return: A pointer to to a string of character up until the delimiter
 */
char *_strtok(char *str, const char *delim)
{
	static char *s;
	static int idx = 0;
	int i, j = 0;

	if (str != NULL)
	{
		s = str;
	}


	while (s[idx] != '\0')
	{
		while (delim[j] != '\0')
		{
			printf("Value at delim[%d] = %c\n", j, delim[j]);
			if (s[idx] == delim[j])
			{
				printf("Value at str[%d] = %c", idx, s[idx]);
				s[idx] = '\0';
				return (s);
			}
			j++;
		}
		idx++;
	}

	printf("idx = %d\n", idx);
	return (s);
}

int main(void)
{
	char *string = "Hello Diego Murray";
	const char delimiter[] = {'o',' ','\0'};
/*	char *p;*/

	printf("First substring: %s \n", _strtok(string, delimiter));

/*	p = _strtok(string, delimiter);
	while (p != NULL)
	{
		printf("%s\n", p);
		p = _strtok(NULL, delimiter);
	}*/
	return (0);
}
