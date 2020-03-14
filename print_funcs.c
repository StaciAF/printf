#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * print_string - prints given string
 * @n: first argument passed
 *
 * Return: Nothing
 */
int print_string(const unsigned int n, ...)
{
/* set variadic functions */
	va_list args;

/* set integer to count size of string */
	int count;
	char *s;

/* initialize args list */
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

/* end argument list */
	va_end(args);

/* returns number of characters printed */
	return (count);
}
