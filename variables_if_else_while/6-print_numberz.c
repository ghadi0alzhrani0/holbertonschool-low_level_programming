#include <stdio.h>
/**
 * main - prints decimal without char
 *
 *Return: Always 0 (Success)
 */
int main(void)
{
	int d = '0';

	while (d <= '9')
	{
		putchar(d);
		d++;
	}
	putchar('\n');
	return (0);
}
