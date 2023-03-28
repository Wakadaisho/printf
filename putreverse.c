#include "main.h"

/**
 * _putreverse - print the revers of string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putreverse(char spec[], va_list args, char *buffer)
{
	int ret = 0, i = 0;
	char *s;

	spec[0] = spec[0];

	s = va_arg(args, char *);

	while (s[i] != '\0')
	{
		i++;
	}

	for (i -= 1; i >= 0; i--)
	{
		ret += _putchar(s[i], buffer);
	}

	return (ret);
}
