#include "shell.h"

/**
 * custom_getline - Collects input from the user
 * @input_buffer: Stores the address of the input collected
 * @buffer_size: Size of the input buffer
 * Return: Number of characters read, 0 on EOF, -1 on failure
 */
int custom_getline(char **input_buffer, size_t *buffer_size)
{
	int chars_read = 0;
	size_t index = 0, new_buffer_size;
	char user_input;
	char *new_input_buffer;

	/* If buffer is not initialized or size is 0, allocate initial memory */
	if (*input_buffer == NULL || *buffer_size == 0)
	{
	*buffer_size = 100;
	*input_buffer = malloc(*buffer_size);
	if (*input_buffer == NULL)
	return (-1);
	}

	/* Read characters until a newline or EOF is encountered */
	for (; (chars_read = read(STDIN_FILENO, &user_input, 1)) > 0;)
	{
	/* Break the loop if a newline is encountered */
	if (user_input == '\n')
	break;

	/* Store the input character in the buffer */
	(*input_buffer)[index++] = user_input;

	/* If the buffer is full, reallocate with double the size */
	if (index == *buffer_size)
	{
	new_buffer_size = *buffer_size * 2;
	new_input_buffer = (char *)malloc(new_buffer_size);
	if (new_input_buffer == NULL)
	return (-1);

	/* Copy the existing content to the new buffer */
	custom_memcpy(new_input_buffer, *input_buffer, *buffer_size);

	/* Free the old buffer and update the pointers and sizes */
	free(*input_buffer);
	*input_buffer = new_input_buffer;
	*buffer_size = new_buffer_size;
	}
	}

	/* Handle the case of EOF with no characters read */
	if (chars_read == 0 && index == 0)
	{
	free(*input_buffer);
	exit(EXIT_SUCCESS);
	}

	/* Null-terminate the string */
	(*input_buffer)[index] = '\0';

	return (chars_read);
}

/**
 * custom_memcpy - Copies previously allocated memory as used in custom_getline()
 * @dest: New location
 * @src: Previous location
 * @num: Size of the input to be copied
 * Return: New location if successful
 */
char *custom_memcpy(char *dest, char *src, unsigned int num)
{
	/* Copy 'num' bytes from source to destination using a for loop */
	for (unsigned int i = 0; i < num; i++)
	{
	dest[i] = src[i];
	}

	return (dest);
}
