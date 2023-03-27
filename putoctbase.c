#include "main.h"

/**
 * _putoctal - print a number passed in args as an octal
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putoctal(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned int n;

	n = va_arg(args, unsigned int);

	spec[0] = spec[0];

	ret += _convertBase(n, 8, 0, buffer);

	return (ret);
}
