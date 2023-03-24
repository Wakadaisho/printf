#include "main.h"

/**
 * _isalpha - returns whether a character is alphabetic
 * @c: character to check
 *
 * Return:	1 if alphabet character
 *			-1 if non-alphabet character
 *
 */
int _isalpha(char c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (1);
	return (-1);
}

