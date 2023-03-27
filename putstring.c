#include "main.h"

/**
 * _putstring - print a string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putstring(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	char *s;

	spec[0] = spec[0];

	s = va_arg(args, char *);

	ret += _putstr(s, buffer);

	return (ret);
}
