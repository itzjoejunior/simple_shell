#include "shell.h"

/**
 * check_exit_command - Check if the input command is the exit command.
 * @command: Input command
 * Return: 1 if the command is exit, 0 otherwise
 */
	int check_exit_command(const char *command)
{
	/* Compare the command with "exit" and return the result */
	return (strncmp(command, "exit", (size_t)4) == 0);
}

/**
 * handle_exit - Handle the exit command. Called in _fork()
 *
 * @buffer: Input buffer
 * Return: Always 0 if successful
 */
int handle_exit(char *buffer)
{
	/* Check if the input buffer contains the exit command */
	if (check_exit_command(buffer))
    {
	/* Free the allocated memory for the buffer */
	free(buffer);

	/* Exit the shell program with success status */
	exit(EXIT_SUCCESS);
	}

	return (0);
}
