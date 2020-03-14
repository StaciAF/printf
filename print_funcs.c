#include "holberton.h"
#include <unistd.h>
/**
 * print_string - prints given string
 * @s: string passed to be printed
 *
 * Return: Nothing
 */
void print_string(char *s)
{
/* set integer to count size of string */
	int count;

/* iterate through string to find length */
	count = 0;
	while (s[count] != '\0')
		count++;

/* prints string to stdout (1) */
	write(1, s, count);
}
