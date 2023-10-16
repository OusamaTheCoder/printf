#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int buff_ind = 0, i;
    char buffer[BUFF_SIZE];

    if (!format)
        return (-1);

    va_start(args, format);
    for (i = 0; format[i]; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
        }
        else
        {
            switch (format[++i])
            {
                case 'c':
                    buffer[buff_ind++] = (char) va_arg(args, int);
                    break;
                case 's':
                {
                    char *str = va_arg(args, char*);
                    int j;
                    for (j = 0; str && str[j]; j++)
                    {
                        buffer[buff_ind++] = str[j];
                        if (buff_ind == BUFF_SIZE)
                            print_buffer(buffer, &buff_ind);
                    }
                    break;
                }
                case '%':
                    buffer[buff_ind++] = '%';
                    break;
                default:
                    i--;
                    buffer[buff_ind++] = format[i];
                    break;
            }
        }
        if (buff_ind == BUFF_SIZE)
            print_buffer(buffer, &buff_ind);
    }
    print_buffer(buffer, &buff_ind);
    va_end(args);

    return (buff_ind);
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);
    *buff_ind = 0;
}

