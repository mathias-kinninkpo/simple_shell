#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_INPUT_SIZE 1024

void display_prompt() {
    printf("#cisfun$ ");
    fflush(stdout);
}

void execute_command(const char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        char *argv[] = {command, NULL};
        execve(command, argv, NULL);
        // If the above line is executed, it means the command execution failed
        perror("Command execution failed");
        _exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return;
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            // End of file condition (Ctrl+D)
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

        if (strlen(input) > 0) {
            execute_command(input);
        }
    }

    return 0;
}

