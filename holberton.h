#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int (*get_print_func(char x))(const unsigned int, ...);
int print_string(const unsigned int n, ...);
int print_char(const unsigned int n, ...);
int print_int(const unsigned int n, ...);
int print_bin(const unsigned int n, ...);
int print_percent(const unsigned int n, ...);
int print_unknown(const unsigned int n, ...);

#endif
