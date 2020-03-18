#include "holberton.h"
/**
 * get_print_func - chooses correct function
 * @x: char passed
 *
 * Return: pointer to function
 */

int (*get_print_func(char x))(const unsigned int, ...)
{
	if (x == 'c')
		return (print_char);
	if (x == 's')
		return (print_string);
	if (x == 'b')
		return (print_bin);
	if (x == '%' || x == '\0')
		return (print_percent);
	if (x == 'd' || x == 'i')
		return (print_int);
	if (x == 'u')
		return (print_uint);
	if (x == 'o')
		return (print_oct);
	if (x == 'x' || x == 'X')
		return (print_hex);
	return (print_unknown);
}
