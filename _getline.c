#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_getline - gets line of input from stream
 * @lineptr: stores address of buffer
 * @bufsize: size of buffer
 * @stream: where line is being read from
 *
 * Return: number of characters copied or -1 if fails.
 */
ssize_t _getline(char *buf, size_t bufsize)
{
	ssize_t total = 0;

	read(0, buf, bufsize);

	return (total);
}

int main(void)
{
	char **lineptr = NULL;
	char *buf = NULL;
	size_t bufsize = 1024;
	printf("before malloc\n");
	buf = malloc(bufsize * sizeof(char));
	if (buf == NULL)
	{
		perror("buffer failed\n");
		exit(1);
	}
	printf("after malloc\n");
	lineptr = &buf;
	printf("assigned lineptr to buf\n");
	printf("$ ");
	_getline(buf, bufsize);
	return (0);
}
