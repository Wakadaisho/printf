#include "main.h"

/**
 * _putint - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putint(char spec[], va_list args, char buffer[])
{
	int ret = 0, power = 1, n, n_cp;

	n = va_arg(args, int);
	spec[0] = spec[0];

	if (n < 0)
	{
		ret += _putchar ('-', buffer);
		n *= -1;
	}

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
