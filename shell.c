#include "shell.h"
/**
 *execute - execute the command
 *@input : the pointer of the input string
 * return : void
 */
void execute(char *input)
{
	pid = fork();
	if (pid < 0)
	{
		printf("fork failed");
		return;
	}
	else if (pid == 0)
	{
		char *argv[] = {input, NULL};

		execve(input, argv, NULL);
		perror("No such file or directory");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		return;
	}
}
