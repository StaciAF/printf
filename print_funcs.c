#include "holberton.h"

/**
 * print_char - prints a character to stdout
 * @c: character to print
 */
void print_char(char c)
{
	/* Allocates a string large enough for one character */
	char *s = malloc(sizeof(char) * 1);

	/* Stores character in the string */
	s[0] = c;

	/* Prints string to stdout */
	write(1, s, 1);

	/* Unallocates the string */
	free(s);
}
