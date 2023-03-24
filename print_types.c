#include "main.h"
#include <unistd.h>

/**
 * _putchar - output a character to standard output
 *
 * @c: character to output
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putcharacter - print a single charater passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putcharacter(char spec[], va_list args)
{
	int ret;

	spec[0] = spec[0];

	ret = _putchar(va_arg(args, int));

	return (ret);
}

/**
 * _putstring - print a string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putstring(char spec[], va_list args)
{
	int ret, temp_ret;
	char *s;

	spec[0] = spec[0];

	s = va_arg(args, char *);
	ret = 0;


	while (*s)
	{
		temp_ret = _putchar(*s);
		if (temp_ret == -1)
			return (-1);

		ret += temp_ret;
		s++;
	}

	return (ret);
}

/**
 * _putint - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putint(char spec[], va_list args)
{
	int ret = 0, power = 1, n, n_cp;

	n = va_arg(args, int);
	spec[0] = spec[0];

	if (n < 0)
	{
		_putchar ('-');
		ret++;
		n *= -1;
	}

	n_cp = n;

	if (n == 0)
	{
		_putchar('0');
		ret++;
	}

	while (n_cp)
	{
		power *= 10;
		n_cp /= 10;
	}

	power /= 10;

	while (n)
	{
		_putchar('0' + n / power);
		n %= power;
		power /= 10;
		ret++;
	}
	return (ret);
}
