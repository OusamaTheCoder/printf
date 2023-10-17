#include "main.h"

/**
 * _puts - Prints a string with a newline character.
 * @str: The string to be printed.
 *
 * Return: Returns the number of characters printed.
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - Writes the character 'c' to the standard output (stdout).
 * @c: The character to be printed.
 *
 * Return: On success, returns 1.
 * On error, returns -1, and sets errno appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

