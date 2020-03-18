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

	/* Converts character to a string */
	s = malloc(sizeof(char) * 1);

	if (s == NULL)
		return (-1);

	va_start(args, n);
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
	int count;
	char *s;
	char *null = "(null)";

	va_start(args, n);

	/* set s to arg list reading char pointer */
	s = va_arg(args, char *);

	if (s == NULL)
	{
		write(1, null, 6);
		return (6);
	}

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
	char *p = malloc(sizeof(char) * 1);

	if (p == NULL)
		return (-1);

	p[0] = '%';

/* prints p to stdout then removes malloc */
	if (n)
	{
		write(1, p, 1);
	}
	free(p);

/* returns number of characters printed */
	return (1);
}

/**
 * print_int - prints an integer
 * @n: number of args
 *
 * Return: num of characters printed
 */
int print_int(const unsigned int n, ...)
{       int i, num, neg = 1, count = 1;
	long int div = 10;
	char *s = malloc(sizeof(char) * 1), *p;
	va_list args;

	if (s == NULL)
		return (-1);
	va_start(args, n);
	num = va_arg(args, int);
	va_end(args);
	if (num < 0)
		neg = -1;
	s[0] = ((num % 10) * neg) + '0';
	while (num / div != 0)
	{       count++;
		p = s;
		s = malloc(sizeof(char) * count);
		if (s == NULL)
			return (malfree(p));
		s[0] = (((num / div) % 10) * neg) + '0';
		for (i = 1; i < count; i++)
			s[i] = p[i - 1];
		free(p);
		div = div * 10;
	}
	if (neg == -1)
	{       p = s;
		count++;
		s = malloc(sizeof(char) * count);
		if (s == NULL)
			return (malfree(p));
		s[0] = '-';
		for (i = 1; i < count; i++)
			s[i] = p[i - 1];
		free(p);
	}
	write(1, s, count);
	free(s);
	return (count);
}

/**
 * print_unknown - prints unkown specifiers as if they are normal characters
 * @n: number of arguments
 *
 * Return: num of characters printed
 */
int print_unknown(const unsigned int n, ...)
{
	va_list args;
	char *s = malloc(sizeof(char) * 2);

	if (s == NULL)
		return (-1);

	va_start(args, n);

	s[0] = va_arg(args, int);
	s[1] = va_arg(args, int);

	write(1, s, 2);
	free(s);
	va_end(args);

	return (2);
}
