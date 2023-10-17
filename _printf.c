#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function.
 * @format: format string
 * @...: values to format and print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c'
					|| format[i + 1] == 's' || format[i + 1] == '%'))
		{
			switch (format[i + 1])
			{
				case 'c':
					count += write(1, (char[]){(char)va_arg(args, int)}, 1);
					i += 2;
					break;
				case 's':
					count += print_str(va_arg(args, char *));
					i += 2;
					break;
				case '%':
					count += write(1, &format[i + 1], 1);
					i += 2;
					break;
			}
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_str - Prints a string.
 * @s: string to print
 * Return: number of characters printed
 */
int print_str(char *s)
{
	int i;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
		;

	write(1, s, i);

	return (i);
}

