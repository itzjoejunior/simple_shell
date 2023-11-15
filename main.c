#include "shell.h"

/**
 * main - Entry point for the Shell program
 * @c: Counts arguments but typecasted (not used) for now
 * @argv: Argument variable, gets the name of the shell program
 * Return: Always 0 (Success)
 */
int main(int c, char **argv)
{
	size_t buffsize = 0;
	char *buffer = NULL, *token[1], *shell_name = argv[0];
	(void)c;

	/* Main shell loop */
	for (;;)
	{
	/* Checks if it's in Interactive mode */
	if (isatty(STDIN_FILENO))
	print_str(STDOUT_FILENO, "$ ");

	/* Collects Input from Users */
	custom_getline(&buffer, &buffsize);

	/* Splits Inputs into tokens */
	tokenize(buffer, token);
	if (token[0] == NULL)
	continue;

	/* Create Child Process */
	_fork(shell_name, token);

	/* Handles errors using the loop in pere_error() */
	print_error(shell_name, NULL, 0);
	}

	/* Free allocated memory */
	free(buffer);

	return (0);
}
