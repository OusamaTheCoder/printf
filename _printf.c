#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	unsigned int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c'
					|| format[i + 1] == 's' || format[i + 1] == '%'))
		{
			switch (format[i + 1])
			{
				case 'c':
					{
						char c = va_arg(args, int);

						printed_chars += write(1, &c, 1);
						i++;
					}
					break;
				case 's':
					{
						char *str = va_arg(args, char*);

						printed_chars += write(1, str, strlen(str));
						i++;
					}
					break;
				case '%':
					printed_chars += write(1, "%", 1);
					i++;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

