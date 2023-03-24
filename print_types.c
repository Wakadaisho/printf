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
