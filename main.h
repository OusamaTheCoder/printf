#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* "start" FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/* "end" FLAGS */

/* "start" SIZES */
#define S_LONG 2
#define S_SHORT 1
/* "end" SIZES */

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int print_str(char *s);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS.c ******************/

/* "start" fuctions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* "end" fuctions to print chars and strings */

/* "start" functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
/* "end" functions to print numbers */

/* "start" functions to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* "end" functions to print memory address */

/* "start" function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* "end" function to print non printable characters */

/* "start" functions to handle other specifiers */
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
/* "end" functions to handle other specifiers */

/* "start" functions to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* "end" functions to print a string in rot 13*/

/* "start" functions to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* "end" functions to print string in reverse*/

/* "start" width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
/* "end" width handler */
/****************** FUNCTIONS.c ******************/


/****************** UTILS ******************/
int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);
/****************** UTILS ******************/

long int convert_size_unsgnd(unsigned long int num, int size);
long int convert_size_number(long int num, int size);

#endif
