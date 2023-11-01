#include "slide_line.h"


/**
 * merge - program that merges identical, adjacent numbers in the array based
 * on the specified direction
 *
 * if two numbers are equal and next to each other, they will be merged
 * into one number that is the sum of the two, and the other number
 * will become zero;
 *
 * @line: the array of integers to be merged
 * @size: the size of the array
 * @dir: the direction of merge, either SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: nothing (void)
 */

void merge(int *line, int size, int dir)
{
	int i = (dir == SLIDE_LEFT) ? 0 : size - 1;
	int end = (dir == SLIDE_LEFT) ? size - 1 : 0;
	int step = (dir == SLIDE_LEFT) ? 1 : -1;

	while (dir == SLIDE_LEFT ? i < end : i > end)
	{
		if (line[i] != 0 && line[i] == line[i + step])
		{
			line[i] += line[i + step];
			line[i + step] = 0;
			i += 2 * step;
		}
		else
		{
			i += step;
		}
	}
}


/**
 * slide - program that slides all the non-zero numbers in the array towards
 * the specified direction
 *
 * zeroes are moved to the opposite end of the direction of the slide;
 *
 * @line: the array of integers to be slided
 * @size: the size of the array
 * @dir: the direction of slide, either SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: nothing (void)
 */


void slide(int *line, int size, int dir)
{
	int i = (dir == SLIDE_LEFT) ? 0 : size - 1;
	int end = (dir == SLIDE_LEFT) ? size : -1;
	int step = (dir == SLIDE_LEFT) ? 1 : -1;
	int last_non_zero = (dir == SLIDE_LEFT) ? -1 : size;

	while (i != end)
	{
		if (line[i] != 0)
		{
			if (dir == SLIDE_LEFT)
			{
				line[++last_non_zero] = line[i];
				if (last_non_zero != i)
				{
					line[i] = 0;
				}
			}
			else
			{
				line[--last_non_zero] = line[i];
				if (last_non_zero != i)
				{
					line[i] = 0;
				}
			}
		}
		i += step;
	}
}

/**
 * slide_line - program that slides and merges an array of integers in
 * the given direction
 *
 * this function applies a slide operation, followed by a merge, and another
 * slide to ensure all merges are completed correctly;
 * it represents one move in the game 2048
 *
 * @line: the array of integers representing the game line
 * @size: the number of elements in the line
 * @direction: the direction to slide and merge, SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL ||
	    (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
	{
		return (0);
	}

	if (direction == SLIDE_LEFT)
	{
		slide(line, size, SLIDE_LEFT);
		merge(line, size, SLIDE_LEFT);
		slide(line, size, SLIDE_LEFT);
	}
	else
	{
		slide(line, size, SLIDE_RIGHT);
		merge(line, size, SLIDE_RIGHT);
		slide(line, size, SLIDE_RIGHT);
	}

	return (1);
}
