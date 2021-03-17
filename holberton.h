#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct formats
{
	char *sym;
	int (*f)(va_list);
} fmts;

int _putchar(char c);
int _printf(const char *format, ...);
int charsFormats(const char *format, va_list args);
int _percent(va_list list);
int _char(va_list list);
int _string(va_list list);
int _integer(va_list list);

#endif
