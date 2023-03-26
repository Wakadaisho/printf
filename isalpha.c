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
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '%'))
		return (1);
	return (-1);
}

