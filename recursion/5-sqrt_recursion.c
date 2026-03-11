#include "main.h"

/**
 * check_sqrt - checks numbers to find the square root
 * @n: number to find the square root of
 * @i: number being tested
 *
 * Return: square root or -1
 */
int check_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (check_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 *
 * Return: square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (check_sqrt(n, 1));
}
