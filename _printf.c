#include "holberton.h"

/**
 * _printf - prints a string according to format
 * @format: format of string to print
 * @...: items to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{       int i, tmp, len = 0, count = 0;
	va_list args;
	int (*func)(const unsigned int, ...);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[len] != '\0')
		len++;
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{       i++;
			func = get_print_func(format[i]);
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i')
				tmp = func(1, va_arg(args, int));
			else if (format[i] == 's')
				tmp = func(1, va_arg(args, char *));
			else if (format[i] == '%')
				tmp = func(1);
			else if (format[i] == 'b' || format[i] == 'u' || format[i] == 'o')
				tmp = func(1, va_arg(args, unsigned int));
			else
				tmp = func(2, format[i - 1], format[i]);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
		else
		{
			func = get_print_func('c');
			count += func(1, format[i]);
		}
	}
	va_end(args);
	return (count);
}
