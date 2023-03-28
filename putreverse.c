#include "main.h"
#include <stdio.h>

/**
 * _putreverse - print the revers of string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putreverse(char spec[], va_list args, char *buffer)
{
	int ret, placer, count = 0, i = 0, length, middle;
	char *s, temp;

	spec[0] = spec[0];

	s = va_arg(args, char *);
	
	for(i = 0; s[i] != '\0'; i++)
	{
		count +=1;
        }

	length = count;
	middle = length / 2;
	


	for (i = 0; i < middle; i++)
	{
		temp = s[i];
		placer= length - (i+1);
		s[i] = s[placer];
		s[placer] = temp;
	}
	
	i = 0;
	while (*s)
	{
		ret =_putchar(s[i], buffer);
		printf("%c", ret);
	}
	
	return(length);
}	
