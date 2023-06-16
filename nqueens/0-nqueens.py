#!/usr/bin/python3

import sys

# Check the number of command-line arguments
if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)

# Check if the argument is a valid number
if not sys.argv[1].isdigit():
    print('N must be a number')
    exit(1)

# Parse the value of N from the command-line argument
N = int(sys.argv[1])

# Check if N is at least 4
if N < 4:
    print('N must be at least 4')
    exit(1)


def queens(N, i, a, b, c, d):
    """
    Recursive generator function to find all solutions
    for the N queens problem.

    Args:
        N (int): The size of the chessboard and the number of queens.
        i (int): The current row being considered.
        a (list): List of occupied columns.
        b (list): List of occupied forward diagonals.
        c (list): List of occupied backward diagonals.
        d (list): List of queen positions.

    Yields:
        list: List of queen positions representing a solution.
    """
    if i < N:
        # Iterate over each column in the current row
        for j in range(N):
            # Check if the current position is safe for a queen
            if j not in a and i+j not in b and i-j not in c:
                # Recursively generate solutions for the next row
                yield from queens(N, i+1, a+[j], b+[i+j], c+[i-j], d+[[i, j]])
    else:
        # All queens have been placed, yield the solution
        yield d


# Find and print all solutions for the N queens problem
for solution in queens(N, 0, [], [], [], []):
    print(solution)
