#include "main.h"

/**
 * _isdigit - Checks if a character is a digit
 * @c: The character to be checked
 * Return: 1 for a digit or 0 for anything else
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
