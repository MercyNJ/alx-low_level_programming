#include "main.h"

/**
 * leet - Encodes a string into 1337speak
 *
 * @ptr: A pointer for the string being encoded
 *
 * Return: ptr value
 */

char *leet(char *ptr)

{
	int i;

	int j;

	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	for (i = 0; ptr[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (ptr[i] == s1[j])
			{
				ptr[i] = s2[j];
			}
		}
	}
	return (ptr);
}
