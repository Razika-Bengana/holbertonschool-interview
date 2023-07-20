#!/usr/bin/python3
""" Calculates water between walls """


def rain(walls):
    """ Calculate the amount of water trapped between walls """

    # Check if the input is a valid list of integers
    if type(walls) is not list or not all(type(n) is int for n in walls):
        return 0

    # Initialize the variable to keep track of the total trapped water units
    total_water_units = 0

    # Initialize the left wall index
    left_wall_index = 0

    # Get the number of walls
    walls_len = len(walls)

    # Iterate through the list of walls
    for current_wall_index in range(0, walls_len - 2):

        # Check if the current wall is higher than 0 and not already processed
        if walls[current_wall_index] > 0 and current_wall_index >=\
           left_wall_index:

            """
            Look for the next wall that is higher or equal to the current wall
            """
            for next_wall_index in range(current_wall_index + 2, walls_len):

                if walls[next_wall_index] >= walls[current_wall_index]:
                    """
                    Calculate the trapped water between the current wall
                    and the next wall
                    """
                    water_level = walls[current_wall_index]

                    for wall_between_index in range(current_wall_index + 1,
                                                    next_wall_index):
                        total_water_units += water_level -\
                            walls[wall_between_index]
                    # Update the left wall index to the next wall
                    left_wall_index = next_wall_index

                    break

    return total_water_units
