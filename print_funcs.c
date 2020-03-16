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
 * @n: first argument passed
 *
 * Return: character count
 */

int print_string(const unsigned int n, ...)
{
	va_list args;


        /* set integer to count size of string */
	va_list args;

	/* set integer to count size of string */
	int count;
	char *s;

	va_start(args, n);

	/* set s to arg list reading char pointer */
	s = va_arg(args, char *);

	/* finds length of string */
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

/**
 * print_percent - prints a percent sign to stdout
 * @n: num of args
 * @...: list of args
 *
 * Return: number of characters printed (always 1)
 */

int print_percent(const unsigned int n, ...)
{
	char *p;
	va_list args;

	va_start(args, n);

/* set p to arg list reading type char */
	p = va_args(args, char);

	while (p)
	{
/* prints p to stdout */
		write(1, p, 1);
	}
	va_end(args);

/* returns number of characters printed */
	return (1);
}
