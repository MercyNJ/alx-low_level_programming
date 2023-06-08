#include "hash_tables.h"

/**
 * hash_table_create - Function that creates a hash table
 * @size: The array size
 *
 * Return: Null - If error occurs
 *         Otherwise - pointer to new created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *created_hash_table;
	unsigned long int i;

	created_hash_table = malloc(sizeof(hash_table_t));

	if (created_hash_table == NULL)
	{
		return (NULL);
	}

	created_hash_table->size = size;
	created_hash_table->array = malloc(sizeof(hash_node_t *) * size);

	if (created_hash_table->array == NULL)
	{
		free(created_hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		created_hash_table->array[i] = NULL;
	}

	return (created_hash_table);
}
