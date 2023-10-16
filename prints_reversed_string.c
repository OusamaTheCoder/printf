#include "main.h"

/**
 *pr_reversed_string - prints the reversed string
 *@str: the string to print
 *
 * Return: the length of string
 */
int pr_reversed_string(va_list str)
{
	int i = 0;
	char *s = va_arg(str, char *);
	
	while(s[i] != '\0')
		i++;
	int len = i;
	
	for (i = len - 1; i >= 0; i--)
		_putchar(s[i]);
	
	return (len);
}_
