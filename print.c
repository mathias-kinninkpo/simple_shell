#include "shell.h"

/**
 * _printf - display a string
 * @str: string
 * Return: None
 */

void _printf(char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
