#include "main.h"

/**
 * _putunsign - print an unsigned integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putunsign(char spec[], va_list args, char *buffer)
{
	unsigned int ret = 0, power = 1, n, n_cp, len = 0;
	form_t form;

	spec[0] = spec[0];

	form = get_form(spec);
	if (form.flag_plus)
		len++;
	if (!form.width && !form.precision)
		form.width = 2;
	if (form.width == -1 || form.precision == -1)
		form.width = va_arg(args, unsigned int);
	n = va_arg(args, unsigned int);
	n_cp = n;

	if (n == 0)
		len++;

	while (n_cp > 9)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
	ret += _putpaddingint(&form, len, buffer);
	while (power)
	{
		ret += _putchar('0' + n / power, buffer);
		n %= power;
		power /= 10;
	}
	return (ret);
}

/**
 * _putunsignlong - print an unsigned integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putunsignlong(char spec[], va_list args, char *buffer)
{
	unsigned long int ret = 0, power = 1, n, n_cp, len = 0;
	form_t form;

	spec[0] = spec[0];

	form = get_form(spec);
	if (form.flag_plus)
		len++;
	if (!form.width && !form.precision)
		form.width = 2;
	if (form.width == -1 || form.precision == -1)
		form.width = va_arg(args, unsigned int);
	n = va_arg(args, unsigned long int);
	n_cp = n;

	if (n == 0)
		len++;

	while (n_cp > 9)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
	ret += _putpaddingint(&form, len, buffer);
	while (power)
	{
		ret += _putchar('0' + n / power, buffer);
		n %= power;
		power /= 10;
	}
	return (ret);
}

/**
 * _putunsignshort - print an unsigned integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putunsignshort(char spec[], va_list args, char *buffer)
{
	unsigned short int ret = 0, power = 1, n, n_cp, len = 0;
	form_t form;

	spec[0] = spec[0];

	form = get_form(spec);
	if (form.flag_plus)
		len++;
	if (!form.width && !form.precision)
		form.width = 2;
	if (form.width == -1 || form.precision == -1)
		form.width = va_arg(args, unsigned int);
	n = va_arg(args, unsigned int);
	n_cp = n;

	if (n == 0)
		len++;

	while (n_cp > 9)
	{
		power *= 10;
		n_cp /= 10;
		len++;
	}
	ret += _putpaddingint(&form, len, buffer);
	while (power)
	{
		ret += _putchar('0' + n / power, buffer);
		n %= power;
		power /= 10;
	}
	return (ret);
}
