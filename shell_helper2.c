#include "holberton.h"

/**
 * memeset - not memset
 * @a: mem address
 * @c: set type
 * @size: size
 *
 * Return: pointer
 */

void *memeset(void *a, int c, int size)
{
	int i;
	unsigned char *p = a;

	for (i = 0 ; i < size ; i++)
	{
		*p = c;
		p++;
	}
	return (a);
}

/**
 * _calloc - calloc
 * @nmemb: elements
 * @size: bytes
 *
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *areigh;

	if (size && nmemb)
	{
		areigh = malloc(nmemb * size);
		if (areigh)
		{
			memeset(areigh, '\0', nmemb * size);
			return (areigh);
		}
	}
	return (NULL);
}
