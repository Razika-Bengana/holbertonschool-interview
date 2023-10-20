#!/usr/bin/python3
"""
Island Perimeter
"""


def island_perimeter(grid):
    """
    function that returns the perimeter of the island described in grid
    """
    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    # Loop through each cell in the grid
    for row in range(rows):
        for col in range(cols):
            # If we find a land cell, check its surroundings
            if grid[row][col] == 1:
                # Check top
                if row == 0 or grid[row-1][col] == 0:
                    perimeter += 1
                # Check bottom
                if row == rows - 1 or grid[row+1][col] == 0:
                    perimeter += 1
                # Check left
                if col == 0 or grid[row][col-1] == 0:
                    perimeter += 1
                # Check right
                if col == cols - 1 or grid[row][col+1] == 0:
                    perimeter += 1
    return perimeter
