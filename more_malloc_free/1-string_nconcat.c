#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2
 *
 * Return: pointer to newly allocated memory, or NULL if failed
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len1, len2, i, j, s2_bytes;

	len1 = 0;
	len2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		s2_bytes = len2;
	else
		s2_bytes = n;

	str = malloc(sizeof(char) * (len1 + s2_bytes + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		str[i] = s1[i];

	for (j = 0; j < s2_bytes; j++)
		str[i + j] = s2[j];

	str[i + j] = '\0';

	return (str);
}
