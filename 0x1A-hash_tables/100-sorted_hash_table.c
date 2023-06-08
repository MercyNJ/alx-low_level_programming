#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the created hash table.
 *
 * Return: NULL - If any error occurs.
 *         a pointer to new sorted hash table on success.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds a new elem to a sorted hash table.
 * @ht: Pointer to a sorted hash table.
 * @key: The key used in addition - must not be an empty string.
 * @value: The value associated with key.
 *
 * Return: On failure - 0.
 *         On success - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *temp_node;
	char *duplicate_value;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	duplicate_value = strdup(value);
	if (duplicate_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp_node = ht->shead;
	while (temp_node)
	{
		if (strcmp(temp_node->key, key) == 0)
		{
			free(temp_node->value);
			temp_node->value = duplicate_value;
			return (1);
		}
		temp_node = temp_node->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(duplicate_value);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(duplicate_value);
		free(new);
		return (0);
	}
	new->value = duplicate_value;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		temp_node = ht->shead;
		while (temp_node->snext != NULL && strcmp(temp_node->snext->key, key) < 0)
			temp_node = temp_node->snext;
		new->sprev = temp_node;
		new->snext = temp_node->snext;
		if (temp_node->snext == NULL)
			ht->stail = new;
		else
			temp_node->snext->sprev = new;
		temp_node->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Obtain value associated with
 *                   a key in a sorted hash table.
 * @ht: Poointer to the sorted hash table.
 * @key: The key whose value to be obtained.
 *
 * Return: If key matching is unsuccessful - NULL.
 *         On success - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Displays a sorted hash table.
 * @ht: Pointer to the sorted hash table to be  printed.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: Pointer to the sorted hash table to be printed.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: Pointer to sorted hash table to be deleted.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *temp_node;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		temp_node = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp_node;
	}

	free(head->array);
	free(head);
}
