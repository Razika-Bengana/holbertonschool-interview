#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

/**
* printarray - print array
* @places: array of 1 and 0
* @size: size of array
*/
void printarray(int **places, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (places[i][j] == 1)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

/**
* changearray - change array
* @places: array double pointer
* @csize: array size
* @mods: array of modules
* @ksize: array size
*/
void changearray(int **places, int csize, int *mods, int ksize)
{
	int i, j, k, n, o, p, q;
	int pattern[3] = {1, 0, 1};

	k = 0, n = 0, o = 0, p = 0, q = 0;

	for (k = 0; k < ksize; k++)
	{
		n = mods[k];
		q = mods[k];
		for (i = 0; i < csize; i++)
		{
			for (j = 0; j < csize; j++)
			{
				if (o > 2)
					o = 0;

				if (p > 2)
					p = 0;

				if (n * pattern[o] == 0 && q * pattern[p] == 0)
				{
					places[i][j] = 0;
				}

				q--;
				if (q <= 0)
				{
					q = mods[k];
					p++;
				}
			}
			n--;
			if (n <= 0)
			{
				n = mods[k];
				o++;
			}
		}
	}
}

/**
* freeplaces - free places
* @places: array of arrays
* @size: size of array
*/
void freeplaces(int **places, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(places[i]);
	}

	free(places);
}


/**
* menger - creates a 2 dimensional menger figure
* @level: int
*/
void menger(int level)
{
	double msize;
	int i, j, maxhole, csize, ksize = 0;
	int **places = NULL;
	int *mods = NULL;

	msize = pow(3, level);
	csize = msize;
	maxhole = (int)msize / 3;
	mods = malloc(sizeof(int) * maxhole);
	places = malloc(sizeof(int *) * csize);

	for (; maxhole > 0; maxhole /= 3)
	{
		mods[ksize] = maxhole;
		ksize++;
	}

	for (i = 0; i < csize; i++)
	{
		places[i] = malloc(sizeof(int *) * csize);
		for (j = 0; j < csize; j++)
		{
			places[i][j] = 1;
		}
	}

	changearray(places, csize, mods, ksize);
	printarray(places, csize);
	freeplaces(places, csize);
	free(mods);
}
