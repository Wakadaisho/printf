#include "main.h"

/**
 * get_spec - return a function corresponding to a format specifier
 *
 * @s: specifier to match a function to
 *
 * Return: int (*)(char [], va_list) - function that was as a binary operator
 */
int (*get_spec(char *s))(char spec[], va_list args, char *buffer)
{
	int i = 0;
	spec_t specs[] = {
		{"%", _putpercent},
		{"c", _putcharacter},
		{"s", _putstring},
		{"d", _putint},
		{"i", _putint},
		{"u", _putunsign},
		{"b", _putbinary},
		{"o", _putoctal},
		{"x", _putlowerhex},
		{"X", _putupperhex},
		{"S", _putspecialstring},
		{"p", _putpointer},
		{"r", _putreverse},
		{"R", _putrot13},
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
 * checkWidth - set the output width if the following are matched
 *
 * @c: character to match to flag
 * @form: form_t struct pointer that holds the flags set
 *
 * Return:	0 - no flag set
 *		1 -flag set
 */
int checkWidth(char c, form_t *form)
{
	int changed = 1;

	if (c == '*')
	{
		form->width = -1;
		changed = 0;
	}
	else if (c <= 9 && c >= 0)
	{
		form->width = form->width * 10 + (c - '0');
	}
	else
	{
		changed = 0;
	}

	return (changed);
}

/**
 * checkPrecision - set the precision if a period is found
 *
 * @c: character to match to flag
 * @form: form_t struct pointer that holds the flags set
 *
 * Return:	0 - no flag set
 *		1 -flag set
 */
int checkPrecision(char c, form_t *form)
{
	int changed = 1;

	if (c == '*')
	{
		form->precision = -1;
		changed = 0;
	}
	else if (c <= 9 && c >= 0)
	{
		form->precision = form->precision * 10 + (c - '0');
	}
	else
	{
		changed = 0;
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
	int flags_done = 0, width_done = 0, precision_done = 0;

	/* looks for a match in by category in the below order */
	while (*p)
	{
		if (*p == '.')
			flags_done = width_done = 1;
		if (flags_done == 0)
		{
			flags_done = !checkFlag(*p, &ret);
		}
		else if (width_done == 0)
		{
			width_done = !checkWidth(*p, &ret);
		}
		else if (precision_done == 0)
		{
			precision_done = !checkPrecision(*p, &ret);
		}
		else
		{
			if (*p == 'l')
			{
				ret.length = 'l';
				break;
			}
			if (*p == 'h')
			{
				ret.length = 'h';
				break;
			}
		}
		p++;
	}
	return (ret);
}
