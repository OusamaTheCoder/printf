#include "main.h"

/**
 * get_precision - Extracts the precision value from
 * the provided format string.
 * @p: Pointer to the current position in the format string.
 * @params: Pointer to the parameter structure which
 * will store the parsed precision value.
 * @ap: Argument list pointer, used if precision is provided
 * as an argument (e.g., ".*").
 *
 * Description:
 * This function parses the precision
 * part of a format string (like ".2" in "%.2f").
 * If precision is specified using an asterisk (e.g., ".*"),
 * the next argument in the va_list is used.
 *
 * Return: Updated pointer position after parsing the precision.
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}

