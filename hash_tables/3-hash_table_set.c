#include "hash_tables.h"
#include <string.h>

/**
 * update_node - updates a node value
 * @node: node
 * @key: key
 * @value: value
 *
 * Return: 1 if updated, 0 if not
 */
int update_node(hash_node_t *node, const char *key, const char *value)
{
	char *copy;

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			copy = strdup(value);
			if (copy == NULL)
				return (0);

			free(node->value);
			node->value = copy;
			return (1);
		}
		node = node->next;
	}

	return (0);
}

/**
 * hash_table_set - adds or updates a node
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (update_node(ht->array[index], key, value) == 1)
		return (1);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
