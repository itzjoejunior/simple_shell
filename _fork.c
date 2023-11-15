#include "shell.h"

/**
 * handle_exit_code - Handles specific exit codes
 * @status_code: Exit code to handle
 */
void handle_exit_code(int status_code)
{
	switch (status_code)
	{
	case 127:
	exit(127);
	break;
	case 2:
	exit(2);
	break;
	/* Add more cases as needed */
	default:
	/* Handle other exit codes or take default action */
	break;
	}
}

/**
 * create_and_execute - Creates a child process and executes
 * a command if CP == 0
 * @program_name: Name of Shell program after compiling (./hsh, ./a.out, etc.)
 * @my_token: Stores the address of the input
 */
void create_and_execute(char *program_name, char **token)
{
	pid_t child_pid;
	int exit_status, status_code;

	/* Creates a child process */
	child_pid = fork();

	/* Exit shell when called */
	exit_shell(token[0]);

	/* Exits if fork fails (-1) */
	if (child_pid == -1)
	{
	print_error(program_name, my_token, 1);
	exit(EXIT_FAILURE);
	}

	/* Calls execute_command() if fork is successful (0) */
	else if (child_pid == 0)
	{
	execute_command(program_name, my_token);
	}

	/* Parent process */
	else
	{
	/* Wait for the child process to end before the parent process continues */
	wait(&exit_status);

	/* Checks if there's no error and exits with status */
	if (WIFEXITED(exit_status) != 0)
	{
	status_code = WEXITSTATUS(exit_status);
	handle_exit_code(status_code);
	}
	}
}
