#include "main.h"

/**
 * execmd - function that execuate the command
 * @argv: pointer of pointer
 * @command: command
 * Return: Nothing
 */


void execmd(char *command, char **argv)
{
	char *actual_command = NULL;
	pid_t id;

	id = fork();

	if (command == NULL || argv == NULL)
		perror("Failure");
	actual_command = get_location(command);
	if (id < 0)
	{
		 perror("fork error");
	}
	if (id == 0)
	{
		if (execve(actual_command, argv, NULL) == 0)
			perror("Error:");
	}
	else
	{
		wait(NULL);
	}
}
