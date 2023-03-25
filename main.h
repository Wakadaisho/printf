#ifndef _MAIN_H_
#define _MAIN_H_
#include <stddef.h>
#include <stdarg.h>

/**
 * _isalpha - returns whether a character is alphabetic
 * @c: character to check
 *
 * Return:	1 if alphabet character
 *			-1 if non-alphabet character
 *
 */
int _isalpha(char c);

/**
 * _putchar - output a character to standard output
 *
 * @c: character to output
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putchar(char c);

/**
 * struct spec_mod - Struct spec_mod
 *
 * @spec: _printf specifier e.g. c, s, d
 * @f: function pointer to a specifier printer defined below
 */
typedef struct spec_mod
{
	char *spec;
	int (*f)(char mod[], va_list args);
} spec_t;

/* typedef on struct spec_mod */
/* typedef struct spec_mod spec_t; */

int (*get_spec(char *s))(char mod[], va_list args);

/**
 * _pow - return the exponent value of a number
 *
 * @n: the base value
 * @e: the exponent
 *
 * Return: integer
 */
int _pow(int n, int e);

/**
 * _convertBase - converts a base 10 number to any base up to 36
 *
 * @n: base 10 number to convert
 * @base: base to convert to
 * @u: flag to specify casing of alphabet characters, > base 10
 *	1 for uppercase, 0 for lowercase
 *
 * Return: int, number of digits in converted value
 */
int _convertBase(unsigned int n, int base, int u);

/**
 * _putcharacter - print a single charater passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putcharacter(char spec[], va_list args);

/**
 * _putstring - print a string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putstring(char spec[], va_list args);

/**
 * _putint - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putint(char spec[], va_list args);

/**
 * _putbinary - print a number passed in args as binary
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putbinary(char spec[], va_list args);

/**
 * _putarg - print a an argument passed in args
 *
 * @s: pointer to location in string word staring with '%'
 * @args: current state of variadic arguments passed
 * @mod_length: number of modifier characters to skip over
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putarg(const char *s, va_list args, int *mod_length);

/**
 * _printf - print a format specified string to standard output
 *
 * @format: format of string to be printed,
 *			dependant on the variadic arguments
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _printf(const char *format, ...);


#endif /* _MAIN_H_ */
