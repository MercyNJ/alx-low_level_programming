#include "hash_tables.h"

/**
 * key_index - Calculates the index at which a key/value pair should
 *             be stored in array of a hash table.
 * @key: The key to get the index of.
 * @size: The array size of the hash table.
 *
 * Return: Index of the key.
 *
 * Description: Utilizes the djb2 algorithm.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
