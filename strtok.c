#include "shell.h"

/**
 * my_strtok - my owrn strtok function
 *
 * @str: string
 * @delim: a constant char
 *
 * Return: a char pointer
 */
char *my_strtok(char *str, const char *delim)
{
	static char *token;
	static char *rest;

	if (str != NULL)
		rest = str;
	if (rest == NULL || *rest == '\0')
		return (NULL);
	token = rest;
	rest = strpbrk(token, delim);

	if (rest != NULL)
	{
		*rest = '\0';
		rest++;
	}
	return (token);
}
