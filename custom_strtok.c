#include "shell.h"

/**
 * custom_strtok - Custom strtok() that splits input or buffer into tokens
 *
 * @input_str: Input string
 * @delimiters: Delimiters that separate the tokens (commands from arguments)
 * Return: First token (token_start or Command) if successful
 */
char *custom_strtok(char *input_str, const char *delimiters)
{
	static char *saved_str;
	char *token_start, *token_end;

	/* Save the input to be parsed, else return NULL if empty */
	if (input_str != NULL)
	saved_str = input_str;
	else if (saved_str == NULL)
	return (NULL);

	/* Find the beginning of the token & return NULL if not found */
	token_start = saved_str;
	for (; *token_start != '\0' && custom_strchr(delimiters, *token_start) != NULL; token_start++)
	;
	if (*token_start == '\0')
	{
	saved_str = NULL;
	return (NULL);
	}

	/* Find the end of token & return NULL if not found, else terminate & update saved_str */
	token_end = token_start;
	for (; *token_end != '\0' && custom_strchr(delimiters, *token_end) == NULL; token_end++)
	;
	if (*token_end == '\0')
	
	saved_str = NULL;
	else
	{
	*token_end = '\0';
	saved_str = token_end + 1;
	}

	return (token_start);
	}

/**
 * custom_strchr - Loop through the input until the end or
 *
 * @search_str: Input string
 * @target_char: Character to search for
 * Return: Pointer to the first occurrence of the character, else NULL
 */
char *custom_strchr(const char *search_str, int target_char)
{
	for (; *search_str != '\0'; search_str++)
	{
	/* Return a pointer to the first occurrence of the character, else NULL */
	if (*search_str == target_char)
	
	return (char *)search_str;
    }

    return (NULL);
}
