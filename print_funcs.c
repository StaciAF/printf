#include "holberton.h"

/**
 * print_char - prints a character to stdout
 * @n: num of args
 * @...: list of args
 *
 * Return: number of characters printed (always 1)
 */
int print_char(const unsigned int n, ...)
{
	char *s;
	va_list args;

	va_start(args, n);

	/* Converts character to a string */
	s = malloc(sizeof(char) * 1);
	s[0] = va_arg(args, int);

	/* Prints string to stdout then discards it */
	write(1, s, 1);
	free(s);

	va_end(args);

	/* Printed one character, so return 1 */
	return (1);
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
