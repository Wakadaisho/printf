 #include "main.h"

/**
 * get_spec_long - return a function corresponding to a format specifier
 *
 * @s: specifier to match a function to
 *
 * Return: int (*)(char [], va_list) - function that was as a binary operator
 */
int (*get_spec_long(char *s))(char spec[], va_list args, char *buffer)
{
	int i = 0;
	spec_t specs[] = {
		{"d", _putintlong},
		{"i", _putintlong},
		{"u", _putunsignlong},
		{"o", _putoctallong},
		{"x", _putlowerhexlong},
		{"X", _putupperhexlong},
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
