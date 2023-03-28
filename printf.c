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
	int ret, i, mod_length;
	char buffer[1024] = {'\0'};

	ret = i = 0;
	va_start(args, format);

	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			ret += _putarg(format + i, args, &mod_length, buffer);
			i += mod_length;
		}
		else
		{
			ret += _putchar(*(format + i++), buffer);
		}
	}
	ret += _writebuffer(buffer);
	va_end(args);
	return (ret);
}

/**
 * _putarg - print a an argument passed in args
 *
 * @s: pointer to location in string word staring with '%'
 * @args: current state of variadic arguments passed
 * @mod_length: number of modifier characters to skip over
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putarg(const char *s, va_list args, int *mod_length, char *buffer)
{
	int ret = 0, i;
	char spec[10];
	int (*f)(char [], va_list, char []);
	form_t form;

	*mod_length = 1;
	spec[0] = s[0];
	while (_isalpha(*(s + *mod_length)) == -1)
	{
		spec[*mod_length] = *(s + *mod_length);
		*mod_length += 1;
	}
	spec[*mod_length] = *(s + *mod_length);
	*mod_length += 1;
	spec[*mod_length] = '\0';
	form = get_form(spec);
	switch (form.length)
	{
		case 'l':
			f = get_spec_long(spec + (*mod_length - 1));
			break;
		case 'h':
			f = get_spec_short(spec + (*mod_length - 1));
			break;
		default:
			f = get_spec(spec + (*mod_length - 1));
			break;
	}
	if (f == NULL)
	{
		for (i = 0; i < *mod_length; i++)
		{
			ret += _putchar(*(spec + i), buffer);
		}
		return (*mod_length - _strlen(spec) - 1);
	}
	ret = f(spec, args, buffer);
	return (ret);
}
