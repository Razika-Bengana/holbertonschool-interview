#!/usr/bin/python3
"""
Making Change
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total
    """
    if type(target_total) is not int or type(coins) is not list or not all(
            [type(coin) is int for coin in coins]):
        print("Invalid arguments")
        return 0

    if target_total <= 0:
        return 0

    coins.sort(reverse=True)

    total_coins = 0
    remainder = target_total
    for denomination in coins:
        if denomination <= remainder:
            num_of_coins = remainder // denomination
            total_coins += num_of_coins
            remainder -= num_of_coins * denomination
        if remainder == 0:
            break

    if total_coins == 0 or remainder != 0:
        return -1

    return total_coins
