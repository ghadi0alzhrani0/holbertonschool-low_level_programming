#include <stdio.h>
/**
 * main - prints alphabets in lower case
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alphabets = 'a';

	while (alphabets <= 'z')
	{
		putchar(alphabets);
		alphabets++;
	}
	putchar('\n');
	return (0);
}
