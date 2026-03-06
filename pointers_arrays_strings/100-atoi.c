#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int digit;
	int result = 0;

	while (s[i] != '\0')
	{
		if (!started && s[i] == '-')
			sign = -sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			digit = s[i] - '0';

			if (result < (INT_MIN + digit) / 10)
			{
				if (sign == -1)
					return (INT_MIN);
				return (INT_MAX);
			}

			result = (result * 10) - digit;
		}
		else if (started)
		{
			break;
		}

		i++;
	}

	if (sign == -1)
		return (result);

	if (result == INT_MIN)
		return (INT_MAX);

	return (-result);
}
