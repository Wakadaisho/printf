#include "main.h"

/**
 * _putpaddingint - output integer padding if needed to standard output
 *
 * @form: flags to use
 * @sign: integer sign (value is length, sign)
 * @buffer: character buffer to store future output
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putpaddingint(form_t *form, int sign, char *buffer)
{
	int ret = 0, len = sign, negative = 0;
	int width = form->width || form->precision;

	if (len < 0)
	{
		len *= -1;
		negative = 1;
	}

	if (form->flag_zero)
	{
		if (form->flag_plus && !negative)
			ret += _putchar('+', buffer);
		if (negative)
			ret += _putchar('-', buffer);
		while (width-- > len)
			ret += _putchar('0', buffer);
	}
	else if (form->flag_space)
	{
		while (width-- > len)
			ret += _putchar(' ', buffer);
		if (form->flag_plus && !negative)
			ret += _putchar('+', buffer);
		if (negative)
			ret += _putchar('-', buffer);
	}
	else
	{
		if (form->flag_plus && !negative)
			ret += _putchar('+', buffer);
		if (negative)
			ret += _putchar('-', buffer);
	}

	return (ret);
}

/**
 * _putpadbase - base conversion padding if needed to standard output
 *
 * @f: flags to use
 * @n: the number in base 10
 * @base: base to convert number to
 * @u: casing of output
 * @buf: buffer to output characters to
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putpadbase(form_t *f, unsigned long int n, int base, int u, char *buf);
{
	int ret = 0, len;
	int width = f->width || f->precision;

	len = _baselength(n, 8);

	if (f->flag_hash)
	{
		switch (base)
		{
			case 8:
			case 16:
				ret += _putchar('0', buf);
				if (u == 1)
				{
					ret += _putchar('X', buf);
				}
				else
				{
					ret += _putchar('x', buf);
				}
				break;
			default:
				break;
		}
	}
	if (f->flag_zero)
	{
		while (width-- > len)
			ret += _putchar('0', buf);
	}
	else if (f->flag_space)
	{
		while (width-- > len)
			ret += _putchar(' ', buf);
	}

	return (ret);
}

