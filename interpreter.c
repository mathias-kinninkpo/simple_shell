#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1)/* if program was found in built ins */
		return (retval);

	/* check for program file system */
	retval = find_program(data);
	if (retval)
	{/* if program not found */
		return (retval);
	}
	else
	{/* if program was found */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{ /* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* I am the child process, I execute the program*/
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* I am the father, I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}

/**
 * split - divide a string in tokens(divise une chaine de caracteres
 * mots(tokens)
 * @str: a string a char pointer
 * @delim: a delimiter a char pointer
 * Return: a pointer of pointer of char
 */

char **split(char *str, const char *delim)
{
	char **tokens = malloc(sizeof(char *));
	char *token = my_strtok(str, delim);
	int count = 0;

	while (token != NULL)
	{
		count++;
		tokens = realloc(tokens, sizeof(char *) * count);
		tokens[count - 1] = token;
		token = my_strtok(NULL, delim);
	}
	tokens = realloc(tokens, sizeof(char *) * (count + 1));
	tokens[count] = NULL;

	return (tokens);
}
