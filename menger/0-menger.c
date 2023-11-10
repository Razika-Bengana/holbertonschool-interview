#include "menger.h"

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
