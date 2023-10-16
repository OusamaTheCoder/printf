#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c': {
                    char c_arg = va_arg(args, int);
                    char str[2];
                    str[0] = c_arg;
                    str[1] = '\0';
                    write(1, str, 1);
                    printed_chars++;
                    break;
                }

                case 's': {
                    char *str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";
                    while (*str_arg)
                    {
                        write(1, str_arg, 1);
                        str_arg++;
                        printed_chars++;
                    }
                    break;
                }

                case 'd':
                case 'i': {
                    int d_arg = va_arg(args, int);
                    char int_str[20];
                    int n = sprintf(int_str, "%d", d_arg);
                    write(1, int_str, n);
                    printed_chars += n;
                    break;
                }

                case '%':
                    write(1, "%", 1);
                    printed_chars++;
                    break;

                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

