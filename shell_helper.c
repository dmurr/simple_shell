#include "holberton.h"

/**
 * _strlen - returns length of str s
 * @s: string to be measured
 *
 * Return: length of s
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * _strcmp - compares s1 and s2
 * @s1: one of the strings in question
 * @s2: one of the strigns in question
 *
 * Return: the difference between the strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0 ; s1[i] != '\0' ; i++)
	{
		if (s2[i] == '\0')
			return (s1[i]);
		if (s2[i] != s1[i])
			return (s1[i] - s2[i]);
	}
	if (s2[i] != '\0')
		return (0 - s2[i]);
	return (0);
}

/**
 * _strcat - Concatanates dest and src
 * @dest: One of the strings in question
 * @src: One of the strings in question
 *
 * Return: the concatanated string
 */

char *_strcat(char *dest, char *src)
{
	int len, i;

	len = _strlen(dest);
	for (i = 0 ; *(src + i) != '\0' ; i++)
	{
		*(dest + (len + i)) = *(src + i);
	}
	return (dest);
}

/**
 * int_arg - integer handling
 * @input: Input int
 *
 * Return: stringified int
 */

char *int_arg(int input)
{
	char *output;
	int len = 1, store = input, store2 = input;

	if (input == 0)
	{
		output = malloc(sizeof(char) * 2);
		output[0] = '0';
		output[1] = '\0';
		return (output);
	}
	if (input < 0)
		len += 1;
	for ( ; store /= 10 ; len++)
		;
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		exit(-1);
	output[len] = '\0';
	len--;
	while (store2)
	{
		if (store2 < 0)
			output[len] = ((store2 % 10) * -1) + '0';
		else
			output[len] = (store2 % 10) + '0';
		store2 /= 10;
		len--;
	}
	if (input < 0)
		output[0] = '-';
	return (output);
}
