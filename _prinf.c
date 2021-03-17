#include "holberton.h"


/**
 * _printf - Parameters for printf
 * @format: list of arguments
 * Return: Printed thing
 */

int _printf(const char *format, ...)
{
	int chars;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);

	chars = charsFormats(format, list);

	va_end(list);
	return (chars);
}

/**
 * charsFormats - Paremters printf
 * @format: list of arguments
 * @args: listing
 * Return: value of print
 */

int charsFormats(const char *format, va_list args)
{
	int x,y, chars, r_val;

	fmts a_listar[] = {{"c", _char}, {"s", _string},
				{"%", _percent}, {"d", _integer}, {"i", _integer}, {NULL, NULL}
	};
	chars = 0;
	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			for (y = 0; a_listar[y].sym != NULL; y++)
			{
				if (format[x + 1] == a_listar[y].sym[0])
				{
					r_val = a_listar[y].f(args);
					if (r_val == -1)
						return (-1);
					chars += r_val;
					break;
				}
			}
			if (a_listar[y].sym == NULL && format[x + 1] != ' ')
			{
				if (format[x + 1] != '\0')
				{
					_putchar(format[x]);
					_putchar(format[x + 1]);
					chars = chars + 2;
}
				else
					return (-1);
			}
		a += 1;
		}
		else
		{
			_putchar(format[x]);
			chars++;
		}
	}
	return (chars);
}
