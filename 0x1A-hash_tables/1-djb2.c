#include "hash_tables.h"

/**
 * hash_djb2 - A Hash function that implements djb2 algorithm.
 * @str: The string to get hash value from.
 *
 * Return: The calculated hash value.
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int current_char;

	hash = 5381;
	while ((current_char = *str++))
	{
		hash = ((hash << 5) + hash) + current_char; /* hash * 33 + current_char */
	}

	return (hash);
}
