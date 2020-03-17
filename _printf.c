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
	int i, len = 0;
	unsigned int count = 0;
	va_list args;
	int (*func)(const unsigned int, ...);

	va_start(args, format);

	while (format[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			func = get_print_func(format[i]);

			switch (format[i])
			{
				case 'c':
					count += func(1, va_arg(args, int));
					break;
				case 's':
					count += func(1, va_arg(args, char *));
					break;
			case '%':
				count += func(1, va_arg(args, int));
				break;
			case 'd':
				count += func(1, va_arg(args, int));
				break;
			case 'i':
				count += func(1, va_arg(args, int));
				break;
			case 'b':
				count += func(1, va_arg(args, unsigned int));
				break;

				default:
					break;
			}
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
