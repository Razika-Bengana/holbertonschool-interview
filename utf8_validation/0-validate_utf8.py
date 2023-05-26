#!/usr/bin/python3
""" Validate unicode data set """


def validUTF8(data):
    """ Validate UTF-8 encoding """

    # Check if the input data is a list of integers
    if not (type(data) is list and all([isinstance(n, int) for n in data])):
        return False

    # Convert negative integers to their corresponding positive values
    data = [n + 256 if n < 0 and n > -129 else n for n in data]

    # Keep only the least significant 8 bits of each integer
    data = [n & 0xFF if n >= 0 else n for n in data]

    try:
        # Try to decode the data using UTF-8 encoding
        bytes(data).decode(encoding='utf-8', errors='strict')
    except (ValueError, UnicodeDecodeError):
        # If decoding fails, the data is not a valid UTF-8 encoding
        return False

    # If decoding succeeds, the data is a valid UTF-8 encoding
    return True
