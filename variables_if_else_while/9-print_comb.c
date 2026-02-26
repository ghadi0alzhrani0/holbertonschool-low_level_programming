#include <stdio.h>
/**
 * main - print decimal with, and space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char d = '0';

	while (d <= '9')

	{
		putchar(d);
		if (d <= '8')
		{
			putchar(',');
			putchar(' ');
		}
		d++;
	}
	putchar('\n');
	return (0);
}
