#!/usr/bin/python3
"""
This module contains a func  that returns,
the perimeter of the island described in grid.
"""


def island_perimeter(grid):
    """Func returning perimeter of an island described in a grid

       Grid repres water by 0 and land by 1.
       Args:
           grid (list): A list of list of ints repres an island.
       Returns:
           The perimeter of the island contained in grid.
    """

    if not grid or not grid[0]:
        return (0)

    rows = len(grid)
    columns = len(grid[0])
    perim = 0

    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == 1:
                perim += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perim -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perim -= 2

    return (perim)
