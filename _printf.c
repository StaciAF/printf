#include "holberton.h"

/**
 * _printf - prints a string according to format
 * @format: format of string to print
 * @...: items to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, tmp, len = 0, count = 0;
	va_list args;
	int (*func)(const unsigned int, ...);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[len] != '\0')
		len++;
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			func = get_print_func(format[i]);
			if (format[i] == 'c')
				tmp = func(1, va_arg(args, int));
			else if (format[i] == 's')
				tmp = func(1, va_arg(args, char *));
			else if (format[i] == '%')
				tmp = func(1);
			else if (format[i] == 'd' || format[i] == 'i')
				tmp = func(1, va_arg(args, int));
			else if (format[i] == 'b')
				tmp = func(1, va_arg(args, unsigned int));
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
