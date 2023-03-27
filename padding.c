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
int _putpaddingint(form_t *form, int sign, char buffer[])
{
	int ret = 0, len = sign, negative = 0;

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
		while (form->width-- > len)
			ret += _putchar('0', buffer);
	}
	else if (form->flag_space)
	{
		while (form->width-- > len)
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

