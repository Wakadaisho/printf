#include "main.h"

/**
 * _pow - return the exponent value of a number
 *
 * @n: the base value
 * @e: the exponent
 *
 * Return: integer
 */
unsigned long int _pow(unsigned long int n, int e)
{
	int i = 0;
	unsigned long int ret = 1;

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
 * @buffer: character buffer to store future output
 *
 * Return: int, number of digits in converted value
 */
int _convertBase(unsigned long int n, int base, int u, char *buffer)
{
	unsigned long int n_copy, result;
	int ret = 0, len = 0;

	n_copy = n;

	if (n == 0)
	{
		ret += _putchar('0', buffer);
		return (ret);
	}

	while (n_copy)
	{
		n_copy /= base;
		len++;
	}

	len--;

	while (len >= 0)
	{
		result = _pow(base, len--);
		if (n / result > 9)
		{
			ret += _putchar('a' - (u  ? 32 : 0) + (n / result) - 10, buffer);
		}
		else
		{
			ret += _putchar('0' + (n / result), buffer);
		}
		n %= result;
	}
	return (ret);
}
