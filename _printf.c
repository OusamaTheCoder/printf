#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * write_char - Write a character to the standard output.
 * @c: The character to write.
 * @count: A pointer to the character count.
 */
void write_char(char c, int *count)
{
        write(1, &c, 1);
        (*count)++;
}

/**
 * write_string - Write a string to the standard output.
 * @str: The string to write.
 * @count: A pointer to the character count.
 */
void write_string(char *str, int *count)
{
        if (str == NULL)
                str = "(null)";
        while (*str)
        {
                write_char(*str, count);
                str++;
        }
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
        int count = 0;
        va_list args;

        va_start(args, format);

        while (format && *format)
        {
                if (*format == '%')
                {
                        format++;
                        if (*format == '\0')
                                break;
                        if (*format == 'c')
                        {
                                char c = va_arg(args, int);

                                write_char(c, &count);
                        }
                        else if (*format == 's')
                        {
                                char *str = va_arg(args, char *);

                                write_string(str, &count);
                        }
                        else if (*format == '%')
                        {
                                write_char('%', &count);
                        }
                        else
                        {
                                write_char('%', &count);
                                write_char(*format, &count);
                        }
                }
                else
                {
                        write_char(*format, &count);
                }
                format++;
        }
        va_end(args);
        return (count);
}

