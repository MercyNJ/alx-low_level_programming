#include "main.h"

/**
 * _strcmp - Compares pointers to two strings.
 *
 * @s1: A pointer to the 1st string to be compared.
 *
 * @s2: A pointer to the 2nd string to be compared.
 *
 * Return: If s1 < s2, -ve difference of the 1st unmatched characters.
 * If s1 == s2, 0.
 * If s1 > s2, the positive difference of the 1st unmatched characters.
 *
 */

int _strcmp(char *s1, char *s2)

{
	int i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
