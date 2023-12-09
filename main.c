#include "main.h"
/**
 * main - entery point
 * @argc: argument
 * @argv: pointer to pointer
 * Return: int value
 */

int main(__attribute__((unused))int argc, char **argv)
{
	char *lineptr = NULL, *temp,  *token;
	size_t n = 0;
	ssize_t nchars_read;
	int i, num_tokens;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "Exiting \n", strlen("Exiting \n"));
			free(lineptr);
			exit(0);
		}
		if (nchars_read <= 1)
			continue;
		temp = strdup(lineptr);
		token = strtok(temp, " \n\t");
		for (num_tokens = 0; token != NULL; num_tokens++)
			token = strtok(NULL, " \n\t");
		argv = malloc(sizeof(char *) * (num_tokens + 1));
		if (argv == NULL)
		{
			return (-1);
		}
		if (strcmp(lineptr, "exit\n") == 0)
                        free(lineptr), exit(0);
                if (strcmp(lineptr, "env\n") == 0)
                {
                        printEnve(temp);
                        continue;
                }
		token = strtok(lineptr, " \n\t");
		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			if (argv[i] == NULL)
			{
				free(argv[i]);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, " \n\t");
		}
		argv[i] = NULL;
		execmd(temp, argv);
		free(argv);
	}
	free(temp);
	return (0);
}
