#include "main.h"

/**
 * _putunsign - print an unsigned integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putunsign(char spec[], va_list args, char buffer[])
{
	unsigned int ret = 0, power = 1, n, n_cp;

	n = va_arg(args, unsigned int);
	spec[0] = spec[0];

	n_cp = n;

	if (n == 0)
	{
		ret += _putchar('0', buffer);
	}

	while (n_cp)
	{
		power *= 10;
		n_cp /= 10;
	}

	power /= 10;

	while (power)
	{
		ret += _putchar('0' + n / power, buffer);
		n %= power;
		power /= 10;
	}
	return (ret);
}
