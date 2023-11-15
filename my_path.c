#include "shell.h"

/**
 * find_executable_path - Finds the full path
 * of the executable in the PATH directories
 * @command: Input or string entered
 * @my_path: PATH environment variable
 * Return: Full path of the executable or NULL if not found
 */
char *find_executable_path(char *command, char *my_path)
{
	char *path_token, *file_path, *my_path_cpy;

	my_path_cpy = custom_strdup(my_path);
	path_token = custom_strtok(my_path_cpy, ":");
	file_path = malloc(custom_strlen(command) + custom _strlen(my_path_cpy) + 2);

	while (path_token != NULL)
	{
	custom_strcpy(file_path, path_token);
	custom_strcat(file_path, "/");
	custom_strcat(file_path, command);
	custom_strcat(file_path, "\0");

	if (access(file_path, X_OK) == 0)
	{
	free(my_path_cpy);
	return (file_path);
	}

	path_token = _strtok(NULL, ":");
	}

	free(file_path);
	free(my_path_cpy);

	return (NULL);
}

/**
 * get_path - Gets the PATH from the environment variable using env().
 *
 * @command: Inputs or string entered
 * Return: Always new_path else NULL if successful
 */
char *get_path(char *command)
{
	char *my_path, *new_path;

	my_path = env("PATH");

	if (my_path)
	{
	new_path = find_executable_path(command, my_path);
	return (new_path);
	}

	return (NULL);
}
