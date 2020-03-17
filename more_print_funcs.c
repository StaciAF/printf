#include "holberton.h"

/**
 * print_bin - prints and unsigned int as binary
 * @n: number of args
 *
 * Return: num of characters printed
 */
int print_bin(const unsigned int n, ...)
{
	unsigned int i, digit, num, count = 0;
	char *s = malloc(sizeof(char) * 1);
	char *p = s;
	va_list args;

	if (s == NULL)
		return (-1);

	/* Prepping variables for use */
	va_start(args, n);
	num = va_arg(args, unsigned int);
	s[0] = '\0';

	/* Algorithm to convert to binary string, digit by digit */
	while (num != 0)
	{
		count++;
		digit = num % 2;
		num = num / 2;
		p = s;
		s = malloc(sizeof(char) * count);

		if (s == NULL)
			return (-1);

		for (i = 0; i < count - 1; i++)
			s[(count - 1) - i] = p[(count - 2) - i];
		free(p);
		s[0] = digit + '0';
	}

	write(1, s, count);

	va_end(args);
	free(s);

	return (count);
}
