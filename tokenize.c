#include "shell.h"

/**
 * is_delimiter - Checks if a character is a delimiter (space or newline)
 * @c: Character to check
 * Return: 1 if it's a delimiter, 0 otherwise
 */
int is_delimiter(char c)
{
	return (c == ' ' || c == '\n');
}

/**
 * tokenize - Splits input or buffer into tokens
 *
 * @buffer: Input
 * @my_token: Store the address of the tokens (commands and arguments)
 */
void tokenize(char *buffer, char **my_token)
{
	int j;

	/* Use a custom tokenizer to split the input buffer into tokens */
	for (j = 0, my_token[j] = strtok_custom(buffer, is_delimiter);
	token[j];
	token[++j] = strtok_custom(NULL, is_delimiter))
	{
	/* Body of the loop is empty as strtok_custom handles token extraction */
	}

	/* Set the last element of my_token to NULL to mark the end of tokens */
	token[j] = NULL;
}
