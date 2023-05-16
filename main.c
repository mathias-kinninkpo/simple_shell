#include "shell.h"

/**
 *execute - execute the command
 *@input : the pointer of the input string
 * return : void
 */
void execute(char *input, char *ar)
{
        pid_t pid = fork();
        if (pid < 0)
        {
                printf("fork failed");
                return;
        }
        else if (pid == 0)
        {
                char *argv[] = {input, NULL};

                execve(input, argv, NULL);
                perror(ar);
                exit(EXIT_FAILURE);
        }
        else
        {
                int status;

                waitpid(pid, &status, 0);
                return;
        }
}

/**
 * main - the main function
 * Return: 0 if sucess another else
 */
int main(int argc, char *argv[])
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("($) ");
		fflush(stdout);
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strlen(input) > 0)
		{
			execute(input, argv[0]);
		}
	}
	return (0);
}

