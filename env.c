#include "main.h"

/**
 * print_string- printing a string
 * @esra: string
 *
 * Return: Nothing
 */

void print_string(char *esra)
{
	int j = 0;
	char c;

	while (esra[j])
	{
		c = esra[j];
		write(STDOUT_FILENO, &c, 1);
		j++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * printEnve - function print the environment
 * Return: int value
 */

int printEnve()
{
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		print_string(environ[i]);
	}
	return (1);
}
