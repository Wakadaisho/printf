#include "main.h"

/**
 * get_spec - return a function corresponding to a fromat specifier
 *
 * @s: specifier to match a function to
 *
 * Return: int (*)(char [], va_list) - function that was as a binary operator
 */
int (*get_spec(char *s))(char spec[], va_list args, char *buffer)
{
	int i = 0;
	spec_t specs[] = {
		{"c", _putcharacter},
		{"s", _putstring},
		{"d", _putint},
		{"i", _putint},
		{"b", _putbinary},
		{"S", _putspecialstring},
		{"p", _putpointer},
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
/**
 * checkFlag - set a flag if a character matches
 *
 * @c: character to match to flag
 * @form: form_t struct pointer that holds the flags set
 *
 * Return:	0 - no flag set
 *		1 -flag set
 */
int checkFlag(char c, form_t *form)
{
	int changed = 1;

	switch (c)
	{
		case ' ':
			form->flag_space = 1;
			break;
		case '+':
			form->flag_plus = 1;
			break;
		case '#':
			form->flag_hash = 1;
			break;
		case '-':
			form->flag_minus = 1;
			break;
		case '0':
			form->flag_zero = 1;
			break;
		default:
			changed = 0;
			break;
	}

	return (changed);
}

/**
 * get_form - return a struct showing what format modifiers are used
 *
 * @form: specifier to get conversion specifiers from
 *
 * Return: struct form_t
 */
form_t get_form(char *form)
{
	form_t ret = {0};
	char *p = form;

	while (*p)
	{
		checkFlag(*p, &ret);
		p++;
	}

	return (ret);
}
