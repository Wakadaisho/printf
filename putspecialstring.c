#include "main.h"

/**
 * _putspecialstring - print a string passed in args, non-printable
 *			characters displaying as hex
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putspecialstring(char spec[], va_list args, char *buffer)
{
	int ret;
	char *s;

	spec[0] = spec[0];

	s = va_arg(args, char *);
	ret = 0;

	while (*s)
	{
		if (*s <= 32 || *s >= 127)
		{
			ret +=	_putchar('\\', buffer);
			ret +=	_putchar('x', buffer);
			if (*s <= 15)
				ret += _putchar('0', buffer);
			ret += _convertBase(*s++, 16, 1, buffer);
		}
		else
		{
			ret += _putchar(*s++, buffer);
		}
	}

	return (ret);
}
