#include "main.h"

/**
 *pr_reversed_string - prints the reversed string
 *@str: the string to print
 *
 * Return: the length of string
 */
int pr_reversed_string(va_list str)
{
	int i = 0, j, len = 0;
	char *s = va_arg(str, char *);

	while (s[i] != '\0')
		i++;

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s[j]);
		len++;
	}
	
	return (len);
}
