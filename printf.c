#include "main.h"

/**
 * _printf - print a format specified string to standard output
 *
 * @format: format of string to be printed,
 *			dependant on the variadic arguments
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int ret, i, _putarg_ret, mod_length;

	ret = i = 0;
	va_start(args, format);

	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			_putarg_ret = _putarg(format + i, args, &mod_length);
			if (_putarg_ret == -1)
				return (-1);
			ret += _putarg_ret;
			i += mod_length;
		}
		else
		{
			_putchar(*(format + i));
			ret++;
			i++;
		}
	}

	va_end(args);
	return (ret);
}

/**
 * _putarg - print a an argument passed in args
 *
 * @s: pointer to location in string word staring with '%'
 * @args: current state of variadic arguments passed
 * @mod_length: number of modifier characters to skip over
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putarg(const char *s, va_list args, int *mod_length)
{
	int ret;
	char spec[5];

	int (*f)(char mod[], va_list);
	*mod_length = 0;

	while (_isalpha(*(s + *mod_length)) == -1)
	{
		spec[*mod_length] = *(s + *mod_length);
		*mod_length += 1;
	}

	spec[*mod_length] = *(s + *mod_length);
	*mod_length += 1;
	spec[*mod_length] = '\0';

	if (spec[0] == '%' && spec[1] == '%')
	{
		_putchar('%');
		*mod_length = 2;
		return (1);
	}

	f = get_spec(spec + (*mod_length - 1));

	if (f == NULL)
		return (-1);

	ret = f(spec, args);

	return (ret);
}
