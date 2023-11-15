#include "shell.h"

/**
 * execute_external_command - Executes an external command using execve
 * @program_name: Name of Shell program after compiling
 * @token: Stores the address of the input
 */
void execute_external_command(char *program_name, char **token)
{
	char *path = NULL;
	int num_execve;

	/* Checks if the input starts with / */
	if (token[0][0] == '/')
	{
	execve(token[0], token, environ);

	/* Prints error msg if execve() is not successful */
	print_error(program_name, token, 2);
	}
	else
	{
	/* Stores the location of the input */
	path = get_path(token[0]);

	if (path == NULL)
	{
	/* Print error msg if path is NULL and exit with 127 */
	print_error(program_name, token, 3);
	exit(127);
	}

	/* Calls the execve() if path is not NULL */
	num_execve = execve(path, token, environ);
	if (num_execve == -1)
	{
	/* Print error msg if execve() is -1 and exit with 127 */
	print_error(program_name, token, 3);
	exit(127);
	}
	}
}

/**
 * execute_command - Process the inputs and produce output. Called in _fork()
 * @program_name: Name of Shell program after compiling (./hsh, ./a.out, etc.)
 * @token: Stores the address of the input
 */
void execute_command(char *program_name, char **token)
{
	execute_external_command(program_name, token);
}
