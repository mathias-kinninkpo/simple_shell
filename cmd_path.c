#include "shell.h"

/**
 * _getenv - get a environment variable
 *
 * Return: a array of all (SUCCESS)
 */

char *_getenv(void)
{
	char **env = ENVIRON;
	char *dirs = NULL;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			dirs = *env + 5;
		/*	strcat(dirs, ":");*/
			break;
		}
		env++;
	}
	return (dirs);
}

/**
 * count_str - return the number of dir contained in path
 *
 * @str: string
 *
 * @d: delimiter
 * Return: a int (SUCCESS)
 */

int count_str(char *str, char const *d)
{
	char **p = split(str, d);
	int cpt = 0;

	if (p == NULL)
		return (cpt);
	while (*p != NULL)
	{
		cpt++;
		p++;
	}
	return (cpt);
}
