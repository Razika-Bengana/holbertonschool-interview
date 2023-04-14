#!/usr/bin/python3
"""
method that calculates the fewest number of operations needed
to result in exactly n H characters in the file
"""


def minOperations(n):
    # If n is 1, we can't perform any operations, so return 0
    if n == 1:
        return 0

    # Initialize the number of operations to 0 and the factor to 2
    operations = 0
    factor = 2

    # Loop while n is greater than 1
    while n > 1:
        # If the current factor divides n, add it to the number of operations
        # and divide n by the factor as many times as possible
        while n % factor == 0:
            operations += factor
            n //= factor

        # Increment the factor to check the next prime number
        factor += 1

    # Return the total number of operations
    return operations
