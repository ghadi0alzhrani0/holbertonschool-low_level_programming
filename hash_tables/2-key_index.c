#include "hash_tables.h"

/**
 * key_index - gets the index of a key
 * @key: the key
 * @size: the size of the array
 *
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
