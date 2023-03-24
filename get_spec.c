#include "main.h"

/**
 * get_spec - return a function corresponding to a fromat specifier
 *
 * @s: specifier to match a function to
 *
 * Return: int (*)(char [], va_list) - function that was as a binary operator
 */
int (*get_spec(char *s))(char spec[], va_list args)
{
	int i = 0;
	spec_t specs[] = {
		{"c", _putcharacter},
		{"s", _putstring},
		{"d", _putint},
		{"i", _putint},
		{NULL, NULL}
	};

	while (specs[i].spec)
	{
		if (*s == *(specs[i].spec))
			return (specs[i].f);
		i++;
	}

	return (NULL);
}
