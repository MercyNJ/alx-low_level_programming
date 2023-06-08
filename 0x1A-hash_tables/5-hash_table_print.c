#include "./hash_tables.h"

/**
 * hash_table_print - Displays a hash table.
 * @ht: A pointer to the hash table to be displayed.
 *
 * Description: Key/value pairs are displayed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current_node;
	unsigned long int index;
	unsigned char comma_needed = 0;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			if (comma_needed == 1)
			{
				printf(", ");
			}
			current_node = ht->array[index];
			while (current_node != NULL)
			{
				printf("'%s': '%s'", current_node->key, current_node->value);
				current_node = current_node->next;
				if (current_node != NULL)
				{
					printf(", ");
				}
			}
			comma_needed = 1;
		}
	}
	printf("}\n");
}
