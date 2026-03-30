#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to the 2 dimensional array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **mee;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	mee = malloc(sizeof(int *) * height);
	if (mee == NULL)
		return (NULL);

	x = 0;
	while (x < height)
	{
		mee[x] = malloc(sizeof(int) * width);
		if (mee[x] == NULL)
		{
			while (x >= 0)
			{
				free(mee[x]);
				x--;
			}
			free(mee);
			return (NULL);
		}
		x++;
	}

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			mee[x][y] = 0;
			y++;
		}
		x++;
	}

	return (mee);
}
