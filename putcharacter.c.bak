#include "main.h"

/**
 * _putcharacter - print a single charater passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putcharacter(char spec[], va_list args, char buffer[])
{
	int ret;

	spec[0] = spec[0];

	ret = _putchar(va_arg(args, int), buffer);

	return (ret);
}
