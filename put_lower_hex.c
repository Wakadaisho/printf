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
int _putlowerhex(char spec[], va_list args, char buffer[])
{
	int ret = 0, n;

	n = va_arg(args, unsigned int);

	spec[0] = spec[0];

	ret += _convertBase(n, 16, 0, buffer);

	return (ret);
}