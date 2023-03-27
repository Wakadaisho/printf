#include "main.h"

/**
 * _isalpha - returns whether a character is alphabetic or '%'
 * @c: character to check
 *
 * Return:	1 for matches
 *		-1 for non-matches
 *
 */
int _isalpha(char c)
{
	switch (c)
	{
		case 'd':
		case 'i':
		case 'u':
		case 'o':
		case 'x':
		case 'X':
		case '%':
		case 'p':
		case 'c':
		case 's':
		case 'b':
		case 'S':
		case 'r':
		case 'R':
			return (1);
		default:
			return (-1);
	}
}

