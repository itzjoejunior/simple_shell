#include "shell.h"

/**
 * print_str - Prints a string to stdout if fd is 1, else stderr
 * @file_desc: 1 for stdout, >2 for stderr
 * @str: String to be printed
 * Return: Always 0 if successful
 */
int print_str(int file_desc, const char *str)
{
	/* Writes the string to stdout or stderr based on file_desc */
	if (file_desc == 1)
	write(STDOUT_FILENO, str, _strlen(str));
	else
	write(STDERR_FILENO, str, _strlen(str));

	return (0);
}

/**
 * print_int - Prints an integer to stdout if fd is 1, else stderr
 * @file_desc: 1 for stdout, >2 for stderr
 * @num: Integer to be printed
 * Return: Always 0 if successful
 */
int print_int(int file_desc, int num)
{
	char num_str[12];

	/* Convert the integer to a string */
	int len = _itoa(num, num_str);

	/* Print the string to stdout or stderr based on file_desc */
	if (file_desc == 1)
	write(STDOUT_FILENO, num_str, len);
	else
	write(STDERR_FILENO, num_str, len);

	return (0);
}
