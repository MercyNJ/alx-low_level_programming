#include "main.h"

/**
 * _print_rev_recursion - Printing string in reverse using
 * recursion.
 *
 * @s: The string to be printed
 */

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;
	s++;
	_print_rev_recursion(s);
	s--;
	_putchar(*s);
}
