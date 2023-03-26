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
int _putstring(char spec[], va_list args, char buffer[])
{
	int ret, temp_ret;
	char *s;

	spec[0] = spec[0];

	s = va_arg(args, char *);
	ret = 0;

	while (*s)
	{
		temp_ret = _putchar(*s, buffer);

		ret += temp_ret;
		s++;
	}

	return (ret);
}
