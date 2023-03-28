#include "main.h"

/**
 * _putrot13- print the rot(13)ed of string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putrot13(char spec[], va_list args, char *buffer)
{
	int ret = 0;
	char *s;
	char *x = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *y = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *head;
	char *x_p;
	char *y_p;


	spec[0] = spec[0];

	head = s = va_arg(args, char *);

	while (*head)
	{
		x_p = x;
		y_p = y;

		while (*x_p)
		{
			if (*head == *x_p)
			{
				ret += _putchar(*y_p, buffer);
				break;
			}
			x_p++;
			y_p++;
		}
		head++;
	}

	return (ret);
}
