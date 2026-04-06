#include "3-calc.h"

/**
 * op_add - adds two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: the sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: the first int
 * @b: the second int
 *
 * Return: the difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two integers
 * @a: the first int
 * @b: the second int
 *
 * Return: result of a * b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integers
 * @a: the first int
 * @b: the second int
 *
 * Return: result of a / b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - finds the remainder of division
 * @a: the first int
 * @b: the second int
 *
 * Return: remainder of a % b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
