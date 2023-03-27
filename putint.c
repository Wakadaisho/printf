#include "main.h"
#include <stdio.h>

/**
 * _putint - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putint(char spec[], va_list args, char *buffer)
{
	int ret = 0, power = 1, n, n_cp, negative = 0, len = 0;
	form_t form;

	n = va_arg(args, int);
	form = get_form(spec);
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	if (form.flag_plus || negative)
		len++;
	if (!form.width)
		form.width = 2;
	n_cp = n;
	while (n_cp)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
	power /= 10;
	ret += _putpaddingint(&form, negative ? -len : len, buffer);
	if (n == 0)
		ret += _putchar('0', buffer);
	while (power)
	{
		ret += _putchar('0' + n / power, buffer);
		n %= power;
		power /= 10;
	}
	return (ret);
}
