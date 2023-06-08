#include "hash_tables.h"

/**
 * hash_table_delete - Deletes an entire hash table.
 * @ht: A pointer to a hash table to be deleted.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *next_node;
	unsigned long int index;

	if (ht == NULL)
	{
		return;
	}

	for (index = 0; index < ht->size; index++)
	{
		temp = ht->array[index];
		while (temp != NULL)
		{
			next_node = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next_node;
		}
	}
	free(ht->array);
	free(ht);
}
