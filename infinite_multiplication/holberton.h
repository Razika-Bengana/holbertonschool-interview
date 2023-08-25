#ifndef HOLBERTON_H
#define HOLBERTON_H


#include <stdlib.h>
#include <unistd.h>


int _putchar(char c);
unsigned int *allocateAndInitializeDigitArray(size_t size);
void multiplyStringsAsIntegers(unsigned int *productDigits, char *multiplierDigits,
                               char *multiplicandDigits, size_t multiplierLength,
                               size_t multiplicandLength);
int isPositiveIntegerString(char *s);
void printError(int statusCode);


#endif /* HOLBERTON_H */
