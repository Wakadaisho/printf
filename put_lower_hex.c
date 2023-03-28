#include "main.h"

/**
 * _putlowerhex - print a number passed in args as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putlowerhex(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned int n;
	form_t form;

	n = va_arg(args, unsigned int);

	form = get_form(spec);

	ret += _putpadbase(&form, n, 16, 1, buffer);

	spec[0] = spec[0];

	ret += _convertBase(n, 16, 0, buffer);

	return (ret);
}

/**
 * _putlowerhexlong - print a number as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putlowerhexlong(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned long int n;
	form_t form;

	n = va_arg(args, unsigned long int);

	form = get_form(spec);

	ret += _putpadbase(&form, n, 16, 1, buffer);

	spec[0] = spec[0];

	ret += _convertBase(n, 16, 0, buffer);

	return (ret);
}

/**
 * _putlowerhexshort - print a number as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putlowerhexshort(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned short int n;

	form_t form;

	n = va_arg(args, int);

	form = get_form(spec);

	ret += _putpadbase(&form, n, 16, 1, buffer);

	spec[0] = spec[0];

	ret += _convertBase(n, 16, 0, buffer);

	return (ret);
}
