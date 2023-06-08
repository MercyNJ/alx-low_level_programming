#include "hash_tables.h"

/**
 * hash_table_get - Obtain the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key whose value we are obtaining.
 *
 * Return: If the key has no match - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
