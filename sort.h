#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* supplied functions */
void print_array(const int *array, size_t size);

/* merge_sort() helpers */
void PrintArray(int *array, int iBeg, int iEnd);
void CopyArray(int *array, int iBeg, int iEnd, int *work_copy);
void TopDownMerge(int *array, int iBeg, int iMid, int iEnd, int *work_copy);
void TopDownSplitMerge(int *work_copy, int iBeg, int iEnd, int *array);
void merge_sort(int *array, size_t size);

#endif /* SORT_H */
