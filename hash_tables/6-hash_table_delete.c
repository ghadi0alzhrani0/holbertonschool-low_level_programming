#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int i;
	int first;

	if (ht == NULL)
		return;

	printf("{");
	first = 1;

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];

		while (temp != NULL)
		{
			if (first == 0)
				printf(", ");

			printf("'%s': '%s'", temp->key, temp->value);
			first = 0;
			temp = temp->next;
		}
	}

	printf("}\n");
}
