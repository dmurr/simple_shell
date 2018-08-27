#include "holberton.h"

void shell_error(struct shell cash, int error)
{
	char *e_buf, colon[] = {':', ' ', '\0'}, new[] = {'\n', '\0'}, *count;
	int buf_len = 0;

	/* Need to initialize malloc memory to 0 */
	e_buf = malloc(sizeof(char) * CHAR_BUF_MAX);
	if (e_buf == NULL)
		exit(1);

	_strcat(e_buf, cash.name);
	_strcat(e_buf, colon);
	count = int_arg(cash.count);
	_strcat(e_buf, count);
	_strcat(e_buf, colon);
	_strcat(e_buf, (cash.p_buf)[0]);
	_strcat(e_buf, colon);
	switch(error)
	{
	case 1:
		_strcat(e_buf, "not found\n");
		write(1, e_buf, _strlen(e_buf));
		break;
	case 2:
		_strcat(e_buf, "Illegal number: ");
		_strcat(e_buf, (cash.p_buf)[1]);
		_strcat(e_buf, new);
		write(1, e_buf, _strlen(e_buf));
		break;
	}
	free(count);
	free(e_buf);
}