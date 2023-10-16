#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _strlen(const char *str);

int _printf(const char *format, ...);


int _putchar(char c);
int handle_string(char *str);


int handle_format(const char *format, va_list args);
const char *skip_format_specifier(const char *format);
int is_format_specifier(char c);


#endif
