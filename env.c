#include "shell.h"

/**
 * find_env_variable - Finds the value of an environment variable
 * @variable_name: Name of the environment variable
 * Return: Value of the environment variable if found, else NULL
 */
char *find_env_variable(char *variable_name)
	{
	int name_len = custom_strlen(variable_name);
	int i = 0;

	while (environ[i] != NULL)
	{
	if (custom_strncmp(environ[i], variable_name, name_len) == 0 && environ[i][name_len] == '=')
	{
	return (environ[i] + name_len + 1);
	}
	i++;
	}

	return (NULL);
	}

/**
 * env - Collects the value of an environment variable
 * @variable_name: Name of the environment variable
 * Return: Value of the environment variable if found, else NULL
 */
	char *env(char *variable_name)
	{
	/* Call the function and store the result in a variable */
	char *value = find_env_variable(variable_name);

	/* Return the result */
	return (value);
}
