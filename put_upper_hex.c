#include "main.h"

/**
 * _putupperhex - print a number passed in args as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putupperhex(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned int n;
	form_t form;

	n = va_arg(args, unsigned int);

	spec[0] = spec[0];

	form = get_form(spec);

	ret += _putpadbase(&form, n, 16, 1, buffer);

	ret += _convertBase(n, 16, 1, buffer);

	return (ret);
}

/**
 * _putupperhexlong - print a number as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putupperhexlong(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned long int n;
	form_t form;

	n = va_arg(args, unsigned long int);

	spec[0] = spec[0];

	form = get_form(spec);

	ret += _putpadbase(&form, n, 16, 1, buffer);

	ret += _convertBase(n, 16, 1, buffer);

	return (ret);
}

/**
 * _putupperhexshort - print a number as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putupperhexshort(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned short int n;

	form_t form;

	n = va_arg(args, int);

	spec[0] = spec[0];

	form = get_form(spec);

	ret += _putpadbase(&form, n, 16, 1, buffer);

	ret += _convertBase(n, 16, 1, buffer);

	return (ret);
}
