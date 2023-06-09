#ifndef _MENGER_H_
#define _MENGER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void freeplaces(int **places, int size);
void changearray(int **places, int csize, int *mods, int ksize);
void printarray(int **places, int size);
void menger(int level);

#endif /* _MENGER_H_ */
