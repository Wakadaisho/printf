#ifndef _MAIN_H_
#define _MAIN_H_
#include <stddef.h>
#include <stdarg.h>

/**
 * _writebuffer - output buffer to
 *
 * @buffer: character buffer to print out
 *
 * Return:	-1 on failure
 *		number of characters written on success;
 */
int _writebuffer(char buffer[]);

/**
 * _strlen - find the length of a buffer
 *
 * @buffer: buffer to find the length of
 *
 * Return: integer
 */
int _strlen(char buffer[]);

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
 * @buffer: character buffer to store future output
 *
 * Return:	-1 on failure
 *			1 on success;
 */
int _putchar(char c, char buffer[]);

/**
 * struct spec_mod - Struct spec_mod
 *
 * @spec: _printf specifier e.g. c, s, d
 * @f: function pointer to a specifier printer defined below
 */
typedef struct spec_mod
{
	char *spec;
	int (*f)(char mod[], va_list args, char buffer[]);
} spec_t;

/* typedef on struct spec_mod */
/* typedef struct spec_mod spec_t; */

int (*get_spec(char *s))(char mod[], va_list args, char buffer[]);

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
 * @buffer: character buffer to store future output
 *
 * Return: int, number of digits in converted value
 */
int _convertBase(unsigned int n, int base, int u, char buffer[]);

/**
 * _putcharacter - print a single charater passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putcharacter(char spec[], va_list args, char buffer[]);

/**
 * _putstring - print a string passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putstring(char spec[], va_list args, char buffer[]);

/**
 * _putint - print an integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putint(char spec[], va_list args, char buffer[]);

/**
 * _putbinary - print a number passed in args as binary
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putbinary(char spec[], va_list args, char buffer[]);

/**
 * _putarg - print a an argument passed in args
 *
 * @s: pointer to location in string word staring with '%'
 * @args: current state of variadic arguments passed
 * @mod_length: number of modifier characters to skip over
 * @buffer: character buffer to store future output
 *
 * Return:	number of characters printed
 *			-1 on failure
 */
int _putarg(const char *s, va_list args, int *mod_length, char buffer[]);

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

/**
 * _putusign - print an unsigned integer passed in args
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putunsign(char spec[], va_list args, char buffer[]);

/**
 * _putoctal - print a number passed in args as an octal
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putoctal(char spec[], va_list args, char buffer[]);

/**
 * _putlowerhex - print a number passed in args as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putlowerhex(char spec[], va_list args, char buffer[]);

/**
 * _putupperhex - print a number passed in args as hexadecimal with lowercase
 *
 * @spec: possible modifier to specifier passed to format in printf
 * @args: current state of variadic arguments passed
 * @buffer: character buffer to store future output
 *
 * Return:      number of characters printed
 *                      -1 on failure
 */
int _putupperhex(char spec[], va_list args, char buffer[]);

#endif /* _MAIN_H_ */
