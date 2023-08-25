#include "holberton.h"

/**
 * allocateAndInitializeDigitArray - program that allocates and initializes
 * an array to store the digits of a base 10 number
 *
 * @size: the size of the array to be allocated
 *
 * Return: a pointer to the initialized array, or NULL on failure
 */

unsigned int *allocateAndInitializeDigitArray(size_t size)
{
	unsigned int *digitArray = NULL;
	size_t i;

	digitArray = malloc(sizeof(unsigned int) * size);
	if (!digitArray)
		return (NULL);

	for (i = 0; i < size; i++)
		digitArray[i] = 0;

	return (digitArray);
}


/**
 * multiplyStringsAsIntegers - program that multiplies two strings of digits
 * represented as ASCII characters and stores the product in an array
 *
 * @productDigits: an array to store the digits of the product
 * @multiplierDigits: the string containing the digits of the multiplier
 * @multiplicandDigits: the string containing the digits of the multiplicand
 * @multiplierLength: the number of digits in the multiplier
 * @multiplicandLength: the number of digits in the multiplicand
 *
 * Return: nothing (void)
 */


void multiplyStringsAsIntegers(unsigned int *productDigits,
			       char *multiplierDigits,
			       char *multiplicandDigits,
			       size_t multiplierLength,
			       size_t multiplicandLength)
{
	int multiplierIndex, multiplicandIndex, sum;
	unsigned char digitMultiplier, digitMultiplicand;

	if (productDigits == NULL || multiplierDigits == NULL ||
	    multiplicandDigits == NULL)
		return;

	for (multiplierIndex = multiplierLength - 1; multiplierIndex >= 0;
	     multiplierIndex--)
	{
		sum = 0;
		digitMultiplier = multiplierDigits[multiplierIndex] - '0';

		for (multiplicandIndex = multiplicandLength - 1;
		     multiplicandIndex >= 0; multiplicandIndex--)
		{
			digitMultiplicand =
				multiplicandDigits[multiplicandIndex] - '0';

			sum += productDigits[multiplierIndex +
					     multiplicandIndex + 1] +
				(digitMultiplier * digitMultiplicand);

			productDigits[multiplierIndex + multiplicandIndex + 1] =
				sum % 10;

			sum /= 10;
		}

		if (sum > 0)
			productDigits[multiplierIndex + multiplicandIndex + 1]
				+= sum;
	}
}


/**
 * isPositiveIntegerString - program that validates if a string represents
 * a positive integer
 *
 * @s: the string to be tested
 *
 * Return: 1 if the string represents a positive integer, 0 otherwise
 */

int isPositiveIntegerString(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}


/**
 * printError - program that prints an error message and exits the program
 * with the specified status code
 *
 * @statusCode: the error code to exit with
 *
 * Return: nothing (void)
 */

void printError(int statusCode)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(statusCode);
}


/**
 * main - the entry point
 *
 * program that multiplies two positive numbers
 *
 * if the number of arguments is incorrect, we print Error, followed by a new
 * line, and we exit with a status of 98;
 * the number 1 and number 2 should only be composed of digits, and if not,
 * we print Error, followed by a new line, and we exit with a status of 98
 *
 * @argc: the number of command line arguments
 * @argv: the array of command line arguments
 *
 * Return: 0 on success, 98 on failure
 */

int main(int argc, char **argv)
{
	size_t i, multiplicandLength, multiplierLength, productLength;
	unsigned int *productDigits = NULL;

	if (argc != 3 || !isPositiveIntegerString(argv[1]) ||
	    !isPositiveIntegerString(argv[2]))
		printError(98);

	for (i = 0, multiplicandLength = 0; argv[1][i]; i++)
		multiplicandLength++;

	for (i = 0, multiplierLength = 0; argv[2][i]; i++)
		multiplierLength++;

	productLength = multiplicandLength + multiplierLength;
	productDigits = allocateAndInitializeDigitArray(productLength);

	if (productDigits == NULL)
		printError(98);

	multiplyStringsAsIntegers(productDigits, argv[1], argv[2],
				  multiplicandLength, multiplierLength);

/* Omit leading zeroes */
	for (i = 0; !productDigits[i] && i < productLength; i++)
	{
	}

	if (i == productLength)
		_putchar('0');

	for (; i < productLength; i++)
		_putchar(productDigits[i] + '0');

	_putchar('\n');

	free(productDigits);

	return (0);
}
