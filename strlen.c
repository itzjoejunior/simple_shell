#include "shell.h"

/**
 * custom_strlen - Gets the length or size of the input.
 *
 * @str: Input string
 * Return: Length or size of the string
 */
int custom_strlen(char *str)
{
	int length;

	/* Loop to calculate the length of the string */
	for (length = 0; str[length] != '\0'; length++)
	;

	return (length);
	}

/**
 * custom_strncmp - Compares input with a specified length of string.
 *
 * @str1: First string
 * @str2: Second string
 * @num: Length or size of string
 * Return: 0 if strings are equal, non-zero otherwise
 */
int custom_strncmp(const char *str1, char *str2, int num)
	{
	int i;

	for (i = 0; num && str1[i] == str2[i]; num--, i++)
	;
	num ? (str1[i] - str2[i]) :
	return  (0);
}

/**
 * custom_strcpy - Copies a string to another location.
 *
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the destination string
 */
char *custom_strcpy(char *dest, char *src)
{
	int index;

	/* Loop to copy characters from source to destination */
	for (index = 0; src[index] != '\0'; index++)
	{
	dest[index] = src[index];
	}
	dest[custom_strlen(src)] = '\0';

	return (dest);
}

/**
 * custom_strcat - Concatenates two strings.
 *
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the destination string
 */
char *custom_strcat(char *dest, char *src)
{
	int dest_index;

	/* Loop to find the end of the destination string */
	for (dest_index = 0; dest[dest_index] != '\0'; dest_index++)
	;

	dest[dest_index] = ' ';

	/* Loop to concatenate characters from source to destination */
	for (int src_index = 0; src[src_index] != '\0'; src_index++, dest_index++)
	{
	dest[dest_index] = src[src_index];
	}
	dest[dest_index] = '\0';

	return (dest);
	}

/**
 * custom_strdup - Duplicates a string to a new location.
 * @str: Input string
 * Return: Pointer to the duplicated string
 */
char *custom_strdup(char *str)
{
	int length = custom_strlen(str) + 1;
	char *new_str = malloc(length);

	if (new_str == NULL)
	return (NULL);

	/* Loop to copy characters from source to the new location */
	for (int i = 0; i < length; i++)
	{
	new_str[i] = str[i];
	}

	return (new_str);
}
