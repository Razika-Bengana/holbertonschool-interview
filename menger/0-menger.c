#include "menger.h"

/**
 * print_sponge - program that determines what character to print at a specific
 * row and column position for a given level of the Menger Sponge
 *
 * the function uses a while loop to check if the current position should be a
 * space or a hash character (`#`);
 * if the position falls in the center of a Menger Sponge pattern,
 * it prints a space, otherwise, it prints a `#`;
 * the center is determined by the current level and the modulo operation
 *
 * @level: the current level of the Menger Sponge being printed
 * @row: the current row in the sponge grid
 * @col: the current column in the sponge grid
 *
 * Return: nothing (void)
 */

void print_sponge(int level, int row, int col)
{
	while (level > 0)
	{
		/* Check if we're in the center of the sponge */
		if (row / (int) pow(3, level - 1) % 3 == 1 && col /
		    (int) pow(3, level - 1) % 3 == 1)
		{
			putchar(' ');
			return;
		}
		level--;
	}
	putchar('#');
}

/**
 * menger - program that is responsible for drawing a 2D Menger Sponge of
 * a specified level
 *
 * this function calculates the size of the sponge based on the level and
 * iterates over a grid of that size;
 * it calls `print_sponge` for each position in the grid to determine whether
 * to print a `#` or a space;
 * the function respects the fractal nature of the Menger Sponge by ensuring
 * the correct pattern at each level
 *
 * @level: the level of the Menger Sponge to draw;
 *         if the level is less than 0, the function does nothing
 *
 * Return: nothing (void)
 */

void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return; /* Nothing if level is less than 0 */

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			print_sponge(level, row, col);
		}
		putchar('\n');
	}
}
