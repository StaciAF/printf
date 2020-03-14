#include "holberton.h"
#include <unistd.h>
/**
 * print_string - prints given string
 * @s: string passed to be printed
 *
 * Return: Nothing
 *
 */
void print_string(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
		;
	write(1, s, count);
}
