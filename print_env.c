#include "shell.h"

/**
 * print_env - display a current environment
 *
 * Return: None (SUCCESS)
 */

void print_env(void)
{
	char **env = ENVIRON;

	while (*env != NULL)
	{
		_printf(*env);
		_printf("\n");
		env++;
	}
}
