#include "main.h"

/**
 * print_integer - print an integer in base 10
 * @i: the integer to be printed
 *
 * Return: the number of characters printed
 */
int print_integer(va_list in)
{
	int a[10];
	int i;
	int x, max, sum = 0;
	int len = 0;

	x = va_arg(in, int);
	max = 1000000000;
	a[0] = x / max;

	i = 1;
	while (i < 10)
	{
		max = max / 10;
		a[i] = (x / max) % 10;
		i++;
	}
	if (x < 0)
	{
		_putchar('-');
		len++;
		for (i = 0; i < 10; i++)
			a[i] = a[i] * (-1);
	}
	i = 0;

	while (i < 10)
	{
		sum = sum + a[i];
		if (i == 9 || sum != 0)
		{
			_putchar('0' + a[i]);
			len++;
		}
		i++;
	}

	return (len);
}

#include "main.h"

/**
 * print_decimal - a function that print a decimal(base 10) number
 * @dec: the decimal to be printed
 *
 * Return: the number of characters printed
 */
int print_decimal(va_list dec)
{
	int a[10];
	int i;
	int x, max, sum = 0;
	int len = 0;

	x = va_arg(dec, int);
	max = 1000000000;
	a[0] = x / max;

	i = 1;
	while (i < 10)
	{
		max = max / 10;
		a[i] = (x / max) % 10;
		i++;
	}
	if (x < 0)
	{
		_putchar('-');
		len++;
		for (i = 0; i < 10; i++)
			a[i] = a[i] * (-1);
	}

	i = 0;
	while (i < 10)
	{
		sum = sum + a[i];
		if (i == 9 || sum != 0)
		{
			putchar('0' + a[i]);
			len++;
		}
		i++;
	}

	return (len);
}


