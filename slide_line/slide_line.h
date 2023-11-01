#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H


#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1


#include <stddef.h>


void merge(int *line, int size, int dir);
void slide(int *line, int size, int dir);
int slide_line(int *line, size_t size, int direction);


#endif /* SLIDE_LINE_H */
