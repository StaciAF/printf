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
	s[0] = '0';
	if (num == 0)
		count++;

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

/**
 * malfree - frees a given pointer and returns -1
 * @p: pointer to free
 *
 * Return: -1
 */
int malfree(void *p)
{
	free(p);
	return (-1);
}

/**
 * print_uint - prints and unsigned int
 * @n: number of args
 *
 * Return: number of characters printed
 */
int print_uint(const unsigned int n, ...)
{
	unsigned int i, num, count = 0;
	unsigned long int div = 1;
	char *s = malloc(sizeof(char) * 1), *p;
	va_list args;

	if (s == NULL)
		return (-1);
	va_start(args, n);
	num = va_arg(args, unsigned int);
	va_end(args);
	s[0] = '0';
	if (num == 0)
		count++;
	while (num / div != 0)
	{
		count++;
		p = s;
		s = malloc(sizeof(char) * count);
		if (s == NULL)
			return (malfree(p));
		s[0] = ((num / div) % 10) + '0';
		for (i = 1; i < count; i++)
			s[i] = p[i - 1];
		free(p);
		div = div * 10;
	}
	write(1, s, count);
	free(s);
	return (count);
}

/**
 * print_oct - prints an integer in octal
 * @n: number of args
 *
 * Return: num of characters printed
 */
int print_oct(const unsigned int n, ...)
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
	s[0] = '0';
	if (num == 0)
		count++;

	/* Algorithm to convert to binary string, digit by digit */
	while (num != 0)
	{
		count++;
		digit = num % 8;
		num = num / 8;
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
