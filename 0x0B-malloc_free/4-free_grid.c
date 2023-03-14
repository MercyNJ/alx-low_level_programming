#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_grid - Frees a 2dimensional array
 * @grid: A 2D grid
 * @height: Grid height
 * Description: Frees memory of grid
 *
 * Return: Nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
