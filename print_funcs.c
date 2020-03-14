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

/**
 * print_string - prints given string
 * @s: string passed to be printed
 *
 * Return: Nothing
 */
void print_string(char *s)
{
        /* set integer to count size of string */
	int count;

        /* iterate through string to find length */
	count = 0;
	while (s[count] != '\0')
		count++;

        /* prints string to stdout (1) */
	write(1, s, count);
}
