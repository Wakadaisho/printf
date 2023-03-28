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

	form = get_form(spec);
	if (form.flag_plus || negative)
		len++;
	if (!form.width && !form.precision)
		form.width = 2;
	if (form.width == -1 || form.precision == -1)
		form.width = va_arg(args, int);
	n = va_arg(args, int);
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	n_cp = n;
	while (n_cp > 9)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
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

/**
 * _putintlong - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putintlong(char spec[], va_list args, char *buffer)
{
	long int ret = 0, power = 1, n, n_cp, negative = 0, len = 0;
	form_t form;

	form = get_form(spec);
	if (form.flag_plus || negative)
		len++;
	if (!form.width && !form.precision)
		form.width = 2;
	if (form.width == -1 || form.precision == -1)
		form.width = va_arg(args, long int);
	n = va_arg(args, int);
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	n_cp = n;
	while (n_cp > 9)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
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

/**
 * _putintshort - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putintshort(char spec[], va_list args, char *buffer)
{
	short int ret = 0, power = 1, n, n_cp, negative = 0, len = 0;
	form_t form;

	form = get_form(spec);
	if (form.flag_plus || negative)
		len++;
	if (!form.width && !form.precision)
		form.width = 2;
	if (form.width == -1 || form.precision == -1)
		form.width = va_arg(args, int);
	n = va_arg(args, int);
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	n_cp = n;
	while (n_cp > 9)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
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
