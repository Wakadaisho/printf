#include "main.h"

/**
 * _putpointer - print a pointer address passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putpointer(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	unsigned long int n;

	spec[0] = spec[0];
	n = va_arg(args, unsigned long int);


	ret += _putchar('0', buffer);
	ret += _putchar('x', buffer);

	ret += _convertBase(n, 16, 0, buffer);

	return (ret);
}
