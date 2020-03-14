#include "holberton.h"

void get_print_func(char x)
{
	if (x == 'c')
		print_char(x);

	if (x == 's')
		print_string(x);
}
