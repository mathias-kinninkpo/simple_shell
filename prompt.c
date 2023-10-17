#include "shell.h"

/**
 * prompt - display a prompt of the shell
 *
 * @str: a char pointer
 * Return: None (SUCCESS)
 */
void prompt(const char *str)
{
	printf("%s ", str);
	fflush(stdout);
}
