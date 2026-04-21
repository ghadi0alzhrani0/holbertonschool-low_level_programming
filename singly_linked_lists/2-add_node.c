#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * str_len - counts string length
 * @str: string
 *
 * Return: length
 */
unsigned int str_len(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * add_node - adds a new node
 * @head: first node
 * @str: string
 *
 * Return: new node or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = str_len(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
