#!/usr/bin/python3
"""
we have to rotate 90 degrees clockwise an n x n 2D matrix
"""


def rotate_2d_matrix(matrix):
    """
    function that rotates the n x n 2D matrix to 90 degrees clockwise
    """

    n = len(matrix)

    # Transpose the matrix in-place
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row of the transposed matrix
    for i in range(n):
        matrix[i] = matrix[i][::-1]
