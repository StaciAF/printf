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
 * @n: first argument passed
 *
 * Return: character count
 */

int print_string(const unsigned int n, ...)
{

	va_list args;


        /* set integer to count size of string */

	int count;
	char *s;


	va_start(args, n);


/* set s to arg list reading char pointer */
	s = va_arg(args, char *);


        /* iterate through string to find length */
	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}

        /* prints string to stdout (1) */
	write(1, s, count);


	va_end(args);

/* returns number of characters printed */
	return (count);
}

int print_percent(const unsigned int n, ...)
{
	char *p;
	va_list args;

	va_start(args, n);
	p = va_args(args, char);

	while (p)
	{
		write(1, p, 1);
	}
	va_end(args);
	return (1);
}
