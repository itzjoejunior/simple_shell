#include "shell.h"

/**
 * print_error - Displays error messages for the shell program.
 *
 * @shell_name: Name of Shell program after compiling
 * @tokens: Stores the address of the input
 * @error_code: Specific numbers for the different error messages
 * Return: Always -1 (EXIT_FAILURE) if successful
 */
int print_error(char *shell_name, char **tokens, int error_code)
{
	static int error_counter = 1;

	/* Increment error counter if error_code is 0 */
	if (!error_code)
	error_counter++;

	/* Print the shell name and error counter to stderr */
	if (error_code)
	{
	print_str(STDERR_FILENO, shell_name);
	print_str(STDERR_FILENO, ": ");
	print_int(STDERR_FILENO, error_counter);
	}

	/* Display error message based on error_code */
	switch (error_code)
	{
	case 1:
	print_str(STDERR_FILENO, ": ");
	print_str(STDERR_FILENO, tokens[0]);
	print_str(STDERR_FILENO, ": Fork Failed\n");
	break;
	case 2:
	print_str(STDERR_FILENO, ": ");
	print_str(STDERR_FILENO, tokens[0]);
	print_str(STDERR_FILENO, ": No such file or directory\n");
	break;
	case 3:
	print_str(STDERR_FILENO, ": ");
	print_str(STDERR_FILENO, tokens[0]);
	print_str(STDERR_FILENO, ": not found\n");
	break;
	}

	return (EXIT_FAILURE);
	}
