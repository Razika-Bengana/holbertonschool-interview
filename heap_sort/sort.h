#ifndef SORT_H
#define SORT_H

#include <stdio.h>

// Function to print the elements of the array
void print_array(const int *array, size_t size);

// Function to get the index of the parent node in a binary heap
int getParentIndex(int index);

// Function to get the index of the left child node in a binary heap
int getLeftChildIndex(int index);

// Function to rearrange the elements in the array to form a valid max heap
void heapify(int *array, size_t size);

// Function to perform the sift-down operation to maintain the max heap property
void siftDown(int *array, size_t size, int start, int end);

// Function to perform Heap Sort on an array of integers
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
