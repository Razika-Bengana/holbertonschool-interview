#!/usr/bin/python3
""" Calculates water between walls """

def rain(walls):
    """ Calculate the amount of water trapped between walls """

    # Check if the input is a valid list of integers
    if type(walls) is not list or not all(type(n) is int for n in walls):
        return 0

    # Initialize the variable to keep track of the total trapped water units
    total_water_units = 0

    # Get the number of walls
    walls_len = len(walls)

    # Iterate through the list of walls
    for current_wall_index in range(1, walls_len - 1):
        left_max = max(walls[:current_wall_index])
        right_max = max(walls[current_wall_index + 1:])

        # Calculate the trapped water between the current wall and the lower of the two boundary walls
        water_level = min(left_max, right_max)
        if water_level > walls[current_wall_index]:
            total_water_units += water_level - walls[current_wall_index]

    return total_water_units
