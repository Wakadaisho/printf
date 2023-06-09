#include "main.h"
#include <unistd.h>

/**
 * _strlen - find the length of a buffer
 *
 * @buffer: buffer to find the length of
 *
 * Return: integer
 */
int _strlen(char *buffer)
{
	int ret = 0;
	int i = 0;

	while (i < 1024 && *(buffer + i++))
		ret++;
	return (ret);
}

/**
 * _writebuffer - output buffer to
 *
 * @buffer: character buffer to print out
 *
 * Return:	-1 on failure
 *		number of characters written on success;
 */
int _writebuffer(char *buffer)
{
	int ret = write(1, buffer, _strlen(buffer));

	buffer[0] = '\0';
	buffer[1] = '\0';

	return (ret);
}

/**
 * _putchar - output a character to standard output
 *
 * @c: character to output
 * @buffer: character buffer to store future output
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putchar(char c, char *buffer)
{
	int ret = 0;

	if (_strlen(buffer) + sizeof(c) >= 1024)
	{
		ret = _writebuffer(buffer);
	}

	buffer[_strlen(buffer)] = c;
	buffer[_strlen(buffer) + 1] = '\0';

	return (ret);
}

/**
 * _putstr - output a string to standard output
 *
 * @s: string to output
 * @buffer: character buffer to store future output
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putstr(char *s, char *buffer)
{
	int ret = 0, temp_ret = 0;

	while (*s)
	{
		temp_ret = _putchar(*s++, buffer);
		if (temp_ret == -1)
			return (-1);
		ret += temp_ret;
	}

	return (ret);
}
