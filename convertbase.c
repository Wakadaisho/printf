#include "main.h"

/**
 * _pow - return the exponent value of a number
 *
 * @n: the base value
 * @e: the exponent
 *
 * Return: integer
 */
int _pow(int n, int e)
{
	int i = 0;
	int ret = 1;

	while (i++ < e)
	{
		ret *= n;
	}

	return (ret);
}

/**
 * _convertBase - converts a base 10 number to any base up to 36
 *
 * @n: base 10 number to convert
 * @base: base to convert to
 * @u: flag to specify casing of alphabet characters, > base 10
 *	1 for uppercase, 0 for lowercase
 *
 * Return: int, number of digits in converted value
 */
int _convertBase(unsigned int n, int base, int u)
{
	unsigned int n_copy = n;
	int ret = 0, len = 0, result;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n_copy)
	{
		n_copy /= base;
		len++;
	}

	ret = len--;

	while (len >= 0)
	{
		result = _pow(base, len--);
		if (n / result > 9)
		{
			_putchar('a' - (u  ? 32 : 0) + (n / result) - 10);
		}
		else
		{
			_putchar('0' + (n / result));
		}
		n %= result;
	}

	return (ret);
}
