#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

int main(void)
{
	char *input = NULL;
	size_t len = 0;

	while (1) {
		printf("%s", PROMPT);
		if (getline(&input, &len, stdin) == -1) {
			perror("Failed to read input");
			exit(EXIT_FAILURE);
		}

		// Remove the newline character from the input
		input[strcspn(input, "\n")] = '\0';

		// Fork a child process to execute the command
		pid_t pid = fork();
		if (pid == -1) {
			perror("Failed to fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			// Child process

			// Execute the command
			if (execlp(input, input, NULL) == -1) {
				perror("Failed to execute command");
				exit(EXIT_FAILURE);
			}
		} else {
			// Parent process

			// Wait for the child to exit
			int status;
			if (waitpid(pid, &status, 0) == -1) {
				perror("Failed to wait for child");
				exit(EXIT_FAILURE);
			}
		}
	}

	return 0;
}
